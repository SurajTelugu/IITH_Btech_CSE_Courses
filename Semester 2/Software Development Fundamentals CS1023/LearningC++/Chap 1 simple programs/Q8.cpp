#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int a,b,c;

  cout<<"Enter the value of first integer:";
  cin>>a;

  cout<<"Enter the value of second integer:";
  cin>>b;

  c=b;
  b=a;
  a=c;

  cout<<"After swapping\n";
  cout<<"The value of first integer:"<<a<<" The value of second integer:"<<b<<endl;


}