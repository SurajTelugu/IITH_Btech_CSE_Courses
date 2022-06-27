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
  unsigned n;
  cout<<"Enter value of n:";
  cin>>n;

  cout<<"Factorial of "<<n<<" is "<<fact(n)<<endl;
  

 return EXIT_SUCCESS;
}