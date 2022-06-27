#include<stdio.h>
#include<stdlib.h> 

struct vector
{
  double *v;
  unsigned int d;

};
typedef struct vector vector;

void initialize_vector(double *v,unsigned int d,double a)
{
  for(unsigned i=0;i<d;i++)
  {
    v[i]=a;
  }
   printf("The vector is:\n(");
 for(unsigned i=0;i<d;i++)
 {
   printf("%lf,",v[i]);
   
 }
 printf("\b)\n");
}

int main()
{
 printf("This program gives a DMA vector of d dimention type double having same value a\n\n");
 unsigned int d;
 double *v,a;

 printf("Enter value of d(NO of Dimentions of vector):");
 scanf("%u",&d);
 printf("Enter value of a:");
 scanf("%lf",&a);

 v=(double*) calloc(d,sizeof(double));

 initialize_vector(v,d,a);

 free(v);
 
/*program end*/ 
 return EXIT_SUCCESS;
}