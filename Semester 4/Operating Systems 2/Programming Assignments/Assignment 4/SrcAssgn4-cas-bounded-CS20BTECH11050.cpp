#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <random>
#include <unistd.h>
#include <mutex>
#include <atomic>
#include <pthread.h>

using namespace std;
using namespace std::chrono;

// Intialising Input globally
unsigned n; // Number of threads
unsigned k; // Number of times each thread has to run
double lm1; // Lambda 1
double lm2; // Lambda 2

pthread_t *threads;      // Taking n Pthreads
atomic_int thread_id(0); // Using Atomic int for thread id

// This lock is used to set Lock for processes using CAS Bounded
atomic<bool> atm_lock(false);

// This Array is used to tell whether a process is waiting or not
bool *Waiting_Q;

// Waiting time and Max_Waiting_time are initialised to 0
double Wait_Time = 0;
double Max_Wait_Time = 0;

// This lock ensures that the systime() does not get used by multiple threads at same time
mutex mx;

// File pointer for output file
FILE *out;

// This function takes care of the message to print as per print specfier
void Print_Message(int num, int tid, char c, string time)
{
  if (c == 'r')
  {
    if (num % 10 == 1 && num % 100 != 11)
      fprintf(out, "%dst CS Requested at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 2 && num % 100 != 12)
      fprintf(out, "%dnd CS Requested at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 3 && num % 100 != 13)
      fprintf(out, "%drd CS Requested at %s by Thread %d\n", num, time.c_str(), tid);

    else
      fprintf(out, "%dth CS Requested at %s by Thread %d\n", num, time.c_str(), tid);
  }

  else if (c == 'e')
  {
    if (num % 10 == 1 && num % 100 != 11)
      fprintf(out, "%dst CS Entered at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 2 && num % 100 != 12)
      fprintf(out, "%dnd CS Entered at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 3 && num % 100 != 13)
      fprintf(out, "%drd CS Entered at %s by Thread %d\n", num, time.c_str(), tid);

    else
      fprintf(out, "%dth CS Entered at %s by Thread %d\n", num, time.c_str(), tid);
  }

  else if (c == 'x')
  {
    if (num % 10 == 1 && num % 100 != 11)
      fprintf(out, "%dst CS Exited at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 2 && num % 100 != 12)
      fprintf(out, "%dnd CS Exited at %s by Thread %d\n", num, time.c_str(), tid);

    else if (num % 10 == 3 && num % 100 != 13)
      fprintf(out, "%drd CS Exited at %s by Thread %d\n", num, time.c_str(), tid);

    else
      fprintf(out, "%dth CS Exited at %s by Thread %d\n", num, time.c_str(), tid);
  }
}

// This function gives time at a particular instant at a precision of microseconds
string getSysTime()
{
  mx.lock();
  string SysTime;
  string temp;
  time_t t = time(NULL);
  temp = ctime(&t);

  // Getting Milliseconds and MicroSeconds
  struct timeval min_time;
  gettimeofday(&min_time, NULL);
  int ms = min_time.tv_usec / 1000, musec = min_time.tv_usec % 1000;

  int hour = stoi(temp.substr(11, 2));
  int min = stoi(temp.substr(14, 2));

  SysTime = to_string(hour) + ":" + to_string(min) + ":" +
            temp.substr(17, 2) + ":" + to_string(ms) + ":" + to_string(musec);

  mx.unlock();
  return SysTime;
}

// This function is the thread function and outputs the times
// at which thread requested, entered and exited critical section
void *testCS(void *args)
{
  thread_id++; // Updating Thread ID
  int tid = thread_id;

  // Random Number Generator
  default_random_engine rand_gen(time(NULL));
  exponential_distribution<double> Distribution1(lm1);
  exponential_distribution<double> Distribution2(lm2);

  string reqEnterTime; // Requested Entry Time
  string actEnterTime; // Actual Entry Time
  string exitTime;     // Exit Time

  for (int i = 0; i < k; i++)
  {
    reqEnterTime = getSysTime();

    // Entry-sec()
    Waiting_Q[tid - 1] = true; // Implementing CAS Bounded
    bool key = true;

    bool exp = false;

    auto start = high_resolution_clock::now();
    while (Waiting_Q[tid - 1] && key)
    {
      if (atomic_compare_exchange_strong(&atm_lock, &exp, true))
        key = false;
      else
        exp = false;
    }
    auto stop = high_resolution_clock::now();

    Waiting_Q[tid - 1] = false;

    double looptime = duration_cast<microseconds>(stop - start).count();
    Wait_Time = Wait_Time + looptime;
    Max_Wait_Time = max(Max_Wait_Time, looptime);

    Print_Message(i + 1, tid, 'r', reqEnterTime);

    // Crtical Section Starts
    actEnterTime = getSysTime();
    Print_Message(i + 1, tid, 'e', actEnterTime);

    double t1 = Distribution1(rand_gen);
    sleep(t1);

    exitTime = getSysTime();

    int j = tid % n;
    while (j != i && !Waiting_Q[j])
    {
      j = (j + 1) % n;
    }

    Print_Message(i + 1, tid, 'x', exitTime);

    if (j == i)
      atm_lock = false;
    else
      Waiting_Q[j] = false;

    // Reminder Section
    double t2 = Distribution2(rand_gen);
    sleep(t2);
  }

  pthread_exit(NULL);
}

int main()
{
  FILE *inp = fopen("inp-params.txt", "r");
  fscanf(inp, "%u %u %lf %lf", &n, &k, &lm1, &lm2);
  fclose(inp);

  out = fopen("CAS_Bounded_output.txt", "w");
  fprintf(out, "Bounded CAS ME Output:\n");

  // Allocating memory for threads
  threads = (pthread_t *)malloc(n * sizeof(pthread_t));

  Waiting_Q = (bool *)malloc(n * sizeof(bool));

  // Creating threads with testCS function
  for (int i = 0; i < n; i++)
  {
    pthread_create(&threads[i], NULL, testCS, NULL);
  }

  // Running threads in Parallel
  for (int i = 0; i < n; i++)
  {
    pthread_join(threads[i], NULL);
  }

  double Avg_Wait_Time = Wait_Time / (n * k);
  // Time in Milliseconds
  // cout << "{" << Avg_Wait_Time * 1e-3 << "," << Max_Wait_Time * 1e-3 << "}" << ";" << endl;

  free(Waiting_Q);
  free(threads);
  return 0;
}