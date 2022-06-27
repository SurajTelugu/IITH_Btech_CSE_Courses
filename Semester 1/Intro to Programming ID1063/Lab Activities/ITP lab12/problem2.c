#include<stdio.h>
#include<stdlib.h> 
int main()
{
  printf("This program dynamically allocates memory and stores values for a m x n Matrix of size double\n\n");

  double **matrix;
  unsigned int m,n,i,j;

  printf("Enter the number of rows of matrix (m):");
  scanf("%u",&m);
  printf("Enter the number of coloumns of matrix (n):");
  scanf("%u",&n);
  printf("\n");

*matrix = (double*)malloc(m*n*sizeof(double));

for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
    printf("Enter a%d%d th  element:",i+1,j+1);
    scanf("%lf",(*matrix+i*n+j));
  }
}
printf("\n");
printf("The matrix you have given is:\n\n");

for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
    printf("%lf\t",*(*matrix+i*n+j));
  }
  printf("\n");
}
printf("\n");

free(*matrix);
  
/*program end*/ 
 return EXIT_SUCCESS;
}