#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<float.h>
#include <math.h>
#include<time.h>

//Defining struct for coordinates and typedef it 
struct coordn
{int x; int y;};
typedef struct coordn coordn;
//Defining NULL pointer for wrong scans 
coordn nullpt = {-1,-1};
// Initiating global source vairable 
coordn source;

// Eucledian Distance function finds distance between two points
float Euclidean_Distance(coordn p1, coordn p2)
{
    float distance = sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
    return distance;
}

// Function to read point in the given format 
coordn getpoint(coordn p)
{
  char* point = (char*) malloc(25*sizeof(char));
  scanf("%s",point);
  
  char* num1 = (char*) malloc(10*sizeof(char));
  char* num2 = (char*) malloc(10*sizeof(char));

  if(point[0]!='('){return nullpt;}

  else
  {
    int i;
    for(i=1;point[i]!=',';i++)
    {
      num1[i-1] = point[i];
    }

    i++;
    int j=0;
    while(point[i]!=')')
    {
      num2[j] = point[i];
      j++; i++;
    }
  }

  p.x = atoi(num1);
  p.y = atoi(num2);

  return p;
}

// global file pointer
FILE* fp;
// Function to read point in the given format from file
coordn getpoints_infile(coordn p)
{
  char* point = (char*) malloc(25*sizeof(char));
 
  fscanf(fp,"%s",point);
  
  char* num1 = (char*) malloc(10*sizeof(char));
  char* num2 = (char*) malloc(10*sizeof(char));

  if(point[0]!='('){return nullpt;}

  else
  {
    int i;
    for(i=1;point[i]!=',';i++)
    {
      num1[i-1] = point[i];
    }

    i++;
    int j=0;
    while(point[i]!=')')
    {
      num2[j] = point[i];
      j++; i++;
    }
  }

  p.x = atoi(num1);
  p.y = atoi(num2);
  
  free(point); free(num1); free(num2);
  return p;
}

// Global variables used in thread function
// Near points in each worker thread array 
coordn* Nearpts; 
// Number of threads defining globally to use in main thread function
unsigned num_of_threads; 
// static variable used in worker thread 
static unsigned count = 0; 
// static variable used in worker thread
static unsigned count1 = 0; 
// points per thread defined globally 
int pts_per_thread; 
// remaining points
int rempts;


// Worker thread functions computes point with minimum distance from given set  
void* Threadfunc(void* args)
{
  coordn* pnts = (coordn*) args;
  float mindistance = FLT_MAX;
  if(rempts==0)
  {
     for(int i=0;i<pts_per_thread;i++)
     {
       float dist = Euclidean_Distance(source,pnts[i]);
       if(dist < mindistance) 
       {
           mindistance = dist;
           Nearpts[count1].x = pnts[i].x;
           Nearpts[count1].y = pnts[i].y;
       }
     }

     count1++;
  }

  else
  {
    if(count<num_of_threads-1)
    {
      for(int i=0;i<pts_per_thread;i++)
     {
       float dist = Euclidean_Distance(source,pnts[i]);
       if(dist < mindistance) 
       {
           mindistance = dist;
           Nearpts[count1].x = pnts[i].x;
           Nearpts[count1].y = pnts[i].y;
       }
     }
     
    }
    else 
    {
      for(int i=0;i<pts_per_thread + rempts;i++)
     {
       float dist = Euclidean_Distance(source,pnts[i]);
       if(dist < mindistance) 
       {
           mindistance = dist;
           Nearpts[count1].x = pnts[i].x;
           Nearpts[count1].y = pnts[i].y;
       }
     }
    }
     count1++; count++;
  }
  
  pthread_exit(NULL);
}

int main()
{
  
  // Getting the input Number of Threads from user
  num_of_threads = 16;
  // Getting the source point in given format
  source.x = 780; source.y = 1720;
  //number of points 
  unsigned num_of_pts;
  scanf("%u",&num_of_pts);
  
  // Assigning values for global variables points per thread and remaining points 
  pts_per_thread = num_of_pts/num_of_threads;
  rempts = num_of_pts%num_of_threads;
  
  fp = fopen("data.txt","r");
  // Taking input points from user
  coordn pts[num_of_pts];
  for(int i=0;i<num_of_pts;i++)
  {
    pts[i] = getpoints_infile(pts[i]); // Getting points from user in given format 
  }
  fclose(fp);
  // Assigning memory for nearpts 
  Nearpts = (coordn*) malloc(num_of_threads*sizeof(coordn));
 // Nearest point obtained from main thread
  coordn Nearestpt;
  
  pthread_t threads[num_of_threads];

  clock_t time; double timetaken;
  time = clock();

  for(int i=0;i<num_of_threads;i++)
  {
    int k = i*pts_per_thread;
    pthread_create(&threads[i],NULL,Threadfunc,(void*)&pts[k]);
  }

  for(int i=0;i<num_of_threads;i++)
  {
    pthread_join(threads[i],NULL);
  }
  
  
  float mindistance = FLT_MAX; 

  for(int i=0;i<num_of_threads;i++)
     {
       float dist = Euclidean_Distance(source,Nearpts[i]);
       if(dist < mindistance) 
       {
           mindistance = dist;
           Nearestpt.x = Nearpts[i].x;
           Nearestpt.y = Nearpts[i].y;
       }
     }

     time = clock() - time;
     timetaken = ((double)time)/CLOCKS_PER_SEC;
     
  printf("(%d,%d)\n",Nearestpt.x,Nearestpt.y);
  printf("[%d %.0lf]\n",num_of_pts,timetaken*1000000);
  
  free(Nearpts);

  return EXIT_SUCCESS;
}
