#include<stdio.h>
#include<stdlib.h> 
struct vector
{
  double *v;
  unsigned int d;

};
typedef struct vector vector;
int main()
{
 printf("This program dynamically allocates memory for d dimentional vector\n\n");
 vector vect;
 printf("Enter the value of d:");
 scanf("%u",&vect.d);

 vect.v = (double*) malloc(vect.d*sizeof(double));

 for(unsigned int i=0;i<vect.d;i++)
 {
   printf("The component of vector in dimension%u:",i+1);
   scanf("%lf",&vect.v[i]);
 }
printf("\n");
printf("The vector is: (");

 for(unsigned int i=0;i<vect.d;i++)
 {
   printf("%lf,",vect.v[i]);
 }
printf("\b)\n");

free(vect.v);

/*program end*/ 
 return EXIT_SUCCESS;
}