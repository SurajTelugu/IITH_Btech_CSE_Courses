#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprime(void* n)
{
  int*m = (int*) n;

  for(int i=2;(i*i)<= *m;i++)
  {
    if(*m/i == 0) {return false;}
  }
  return true;
}

int main() 
{
 void *n;
 scanf("%d",(int*)n);
 bool check = false;
 
 check  =  isprime(n);

 if(check == true) {printf("true");}
 else {printf("false");}

  return EXIT_SUCCESS;
}