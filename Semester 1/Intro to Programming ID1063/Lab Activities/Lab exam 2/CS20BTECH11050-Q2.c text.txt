#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct point
{
 double x;
 double y;
};

typedef struct point point;

double dist_btwn_2points(point a,point b)
{
  double dist=sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));

  return dist;
}

int main()
{
  printf("This program finds the Shortest Distance between two Points amoung given set of n Points in 2 Dimentional Space\n\n");

  unsigned int n,i,j;
  printf("Enter Value of n:");
  scanf("%u",&n);
  printf("\n");

  point pnt[n];
  for(i=0;i<n;i++)
  {
    j=0;
    printf("Enter the x coordinate of point %u:",j=i+1);
    scanf("%lf",&pnt[i].x);
    printf("Enter the y coordinate of point %u:",j=i+1);
    scanf("%lf",&pnt[i].y);
  }
   printf("\n");

  unsigned int k=(pow(n,2)-n)/2;
  double D[k];
  unsigned int t=0;

   for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
      D[t]=dist_btwn_2points(pnt[i],pnt[j]);
      t++;
     }
   }

  double min_dist=D[0];

  for(t=1;t<k;t++)
  {
    if(D[t]<min_dist){min_dist=D[t];}
  }

 printf("The Minimum Distance amoung all given points is:%lf\n",min_dist);

  double max_dist=D[0];

  for(t=1;t<k;t++)
  {
      if(D[t]>max_dist) {max_dist=D[t];}
  }

  printf("The Maximum Distance amoung all given points is:%lf\n",max_dist);


/*program end*/
 return EXIT_SUCCESS;
}
