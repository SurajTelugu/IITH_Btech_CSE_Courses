#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  int a,b;
  cout<<"Enter first number:";
  cin>>a;
  cout<<"Enter second number:";
  cin>>b;

if(a%b ==0)
{cout<<"First number is divided by second number and quotient is "<<a/b<<endl;}
else{cout<<"First number is not divided by second number reminder = "<<a%b<<endl;}
 
 return EXIT_SUCCESS;
}