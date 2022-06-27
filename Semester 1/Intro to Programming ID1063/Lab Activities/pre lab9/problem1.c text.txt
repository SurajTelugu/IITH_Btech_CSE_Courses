#include<stdio.h>
#include<stdlib.h> 
int main()
{
  printf("This program prints addresses of a 3 dimentional array locations 2x3x4 of type float:\n\n");
  float array_3d[2][3][4];
  unsigned int i,j,k;

  printf("The Addresses of the Arrays are as follows:\n\n");

  for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
    {
      for(k=0;k<4;k++)
      {
        printf("The Address of Array[%u][%u][%u] is %p\n",i,j,k,&array_3d[i][j][k]);
      }
      
    }
  
    
  }
 
/*program ends*/ 
 return EXIT_SUCCESS;
}