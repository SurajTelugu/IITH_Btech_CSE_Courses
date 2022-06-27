#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <thread>
#include <unistd.h>
#include <pthread.h>
#include <random>
#include <string>
#include <sstream>
#include <bits/stdc++.h> 
#include <sys/time.h>

using namespace std;

ofstream fout_log,fout_stat;
int nw, nr, kw, kr;
double mu_cs, mu_rem;
int read_count = 0;
sem_t rw_mutex, mutext;
vector<thread> writer_thread;
vector<thread> reader_thread;
vector<double> rand_cs_time;
vector<double> rand_rem_time;
int rand_cs = 0, rand_rem = 0;
double avg_writer = 0,avg_reader = 0,sum_writer = 0, sum_reader = 0, worst_writer = 0,worst_reader = 0;

void writer();
void reader();
string getSysTime();

int main()
{
	ifstream fin;
	fin.open("inp-params.txt");
	fin>>nw>>nr>>kw>>kr>>mu_cs>>mu_rem;
	fin.close();

	sem_init(&rw_mutex, 0, 1);
	sem_init(&mutext, 0, 1);

	default_random_engine rand_cs_generator;
	default_random_engine rand_rem_generator;
	exponential_distribution<double> rand_cs_distribution(1 / mu_cs);
	exponential_distribution<double> rand_rem_distribution(1 / mu_rem);
	for(int i = 0; i < ((nw * kw) + (nr * kr)); i++)
	{
		double temp1 = rand_cs_distribution(rand_cs_generator);
		double temp2 = rand_rem_distribution(rand_rem_generator);
		rand_cs_time.push_back(temp1);
		rand_rem_time.push_back(temp2);
	}

	fout_log.open("RW-log.txt");
	fout_stat.open("RW-average_time.txt");

	for(int i = 0; ((i < nw)||(i < nr)); i++)
	{
		if(i < nw)
		{
			writer_thread.push_back(thread(writer));
		}
		if(i < nr)
		{
			reader_thread.push_back(thread(reader));
		}
	}

	for(thread &t : writer_thread)
	{
		t.join();
	}

	for(thread &t : reader_thread)
	{
		t.join();
	}

	fout_stat<<"Reader-Writer :\n";
	fout_stat<<"nw = "<<nw<<";\tnr = "<<nr<<";\tkw = "<<kw<<";\tkr = "<<kr<<";\tmu_cs = "<<mu_cs<<"millisecond;\tmu_rem = "<<mu_rem<<"millisecond;\n";
	fout_stat<<"Worst waiting time of Writer Thread = "<<(double)worst_writer / 1000.00<<"millisecond;\n";
	fout_stat<<"Worst waiting time of Reader Thread = "<<(double)worst_reader / 1000.00<<"millisecond;\n";
	fout_stat<<"Average waiting time of Writer Thread = "<<((double)sum_writer / (1000.00 * nw * kw))<<"millisecond;\n";
	fout_stat<<"Average waiting time of Reader Thread = "<<((double)sum_reader / (1000.00 * nr * kr))<<"millisecond;\n";


	fout_log.close();
	fout_stat.close();

	sem_destroy(&rw_mutex);
	sem_destroy(&mutext);

	return 0;
}

void writer()
{
	thread::id id = this_thread::get_id();
	stringstream ss;
	ss << id;
	for(int i = 0; i < kw; i++)
	{
		struct timeval start, end;
		stringstream st;
		st << ( i + 1);
		string req_time = getSysTime();
		gettimeofday(&start,NULL);
		string z1 =  st.str() + "th CS request by Writer Thread " + ss.str() + " at " + req_time;
		fout_log<<z1;
		sem_wait(&rw_mutex);
		string enter_time = getSysTime();
		gettimeofday(&end,NULL);
		int tt = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
		if(tt > worst_writer)
		{
			worst_writer = tt;
		}
		sum_writer += tt;
		string z2 =  st.str() + "th CS Entry by Writer Thread " + ss.str() + " at " + enter_time;
		fout_log<<z2;
		useconds_t cs = (rand_cs_time[rand_cs++] / 1000) * 1000000;
		usleep(cs);
		sem_post(&rw_mutex);
		string exit_time = getSysTime();
		string z3 =  st.str() + "th CS Exit by Writer Thread " + ss.str() + " at " + exit_time;
		fout_log<<z3;
		useconds_t rem = (rand_rem_time[rand_rem++] / 1000) * 1000000;
		usleep(rem);
	}
}

void reader()
{
	thread::id id = this_thread::get_id();
	stringstream ss;
	ss << id;
	for(int i = 0; i < kr; i++)
	{
		struct timeval start, end;
		stringstream st;
		st << i+1;
		string req_time = getSysTime();
		gettimeofday(&start,NULL);
		string z1 =  st.str() + "th CS request by Reader Thread " + ss.str() + " at " + req_time;
		fout_log<<z1;
		sem_wait(&mutext);
		read_count++;
		if(read_count == 1)
		{
			sem_wait(&rw_mutex);
		}
		sem_post(&mutext);
		string enter_time = getSysTime();
		gettimeofday(&end,NULL);
		int tt = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
		if(tt > worst_reader)
		{
			worst_reader = tt ;
		}
		sum_reader += tt;
		string z2 =  st.str() + "th CS Entry by Reader Thread " + ss.str() + " at " + enter_time;
		fout_log<<z2;
		useconds_t cs = (rand_cs_time[rand_cs++] / 1000) * 1000000;
		usleep(cs);
		sem_wait(&mutext);
		read_count--;
		if(read_count == 0)
		{
			sem_post(&rw_mutex);
		}
		sem_post(&mutext);
		string exit_time = getSysTime();
		string z3 =  st.str() + "th CS Exit by Reader Thread " + ss.str() + " at " + exit_time;
		fout_log<<z3;
		useconds_t rem = (rand_rem_time[rand_rem++] / 1000) * 1000000;
		usleep(rem);
	}
}

string getSysTime()
{
	time_t current_time = time(NULL);
	string temp = ctime(&current_time);
	while(temp[0] == '\00')
		temp = ctime(&current_time);
	return temp;
}