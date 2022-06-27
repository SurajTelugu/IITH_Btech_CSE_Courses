#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  int a,b;
  int *p1=&a; int *p2=&b;

  cout<<"Enter first number:";
  cin>>*p1;

  cout<<"Enter second number:";
  cin>>*p2;

if(*p1>=*p2)
{
  if(*p1==*p2) {cout<<"\nBoth numbers are equal\n";}
  else {cout<<"\nMax Number is "<<*p1<<endl;}
}

else{cout<<"\nMax Number is "<<*p2<<endl;}

 return EXIT_SUCCESS;
}