#include<stdio.h>
#include<stdlib.h> 
void swap_values(double *x,double *y)
{
  double tmp;
  tmp=*x;
  *x=*y;
  *y=tmp;
}
int main()
{
  printf("This program swaps the values of two variables by passing their addresses\n\n");

  double a,b;
  double *pa=&a;
  double *pb=&b;

  printf("Let variables you want to swap be a,b of type double\n");
  printf("Enter the value of a:");
  scanf("%lf",pa);
  printf("Enter the value of b:");
  scanf("%lf",pb);
  printf("\n");

  swap_values(pa,pb);

  printf("After Swapping\n");

  printf("The value of a is:%lf\n",a);
  printf("The value of b is:%lf\n",b);
  
/*program ends*/ 
 return EXIT_SUCCESS;
}