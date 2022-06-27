#include <stdio.h>
#include <stdlib.h>


int main()
{
 printf("This Program accepts a Positive Integer n and adds the number with digits Reverse of n \n\n");

unsigned n,num,rev_n=0,sum;

printf("Enter the value of n:");
scanf("%u",&n);

num =n;

while(num != 0)
{
  rev_n = (rev_n*10) + (num%10);
  num/=10;
}

printf("The number reversing digits of n = %u\n",rev_n);
printf("\n");
sum = rev_n + n;

printf("The sum given number and number obtained by reversing the digits = %u\n",sum);
  return EXIT_SUCCESS;
}