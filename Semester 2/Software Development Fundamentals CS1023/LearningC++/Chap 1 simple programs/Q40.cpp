#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned fact(unsigned n)
{
  if(n == 0) {return 1;}
  if(n == 1) {return 1;}
  if(n == 2) {return 2;}
  else {return n*fact(n-1);}
}


int main()
{
  unsigned n,i=1;
  cout<<"Number of terms in the series:";
  cin>>n;
  float x,sum=0;
  cout<<"Enter value of x:";
  cin>>x;

  while(i<=2*n-1)
  {
    sum = sum + (pow(x,i)/fact(i));
    i = i + 2; 
  }

  cout<<"The sum of series is "<<sum<<endl;
  

 return EXIT_SUCCESS;
}