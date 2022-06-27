#include <iostream>
#include <math.h>

using namespace std;



int main()
{
 int a,b,c;

 cout<<"Enter first number:";
 cin>>a;

 cout<<"Enter second number:";
 cin>>b;

 cout<<"Enter third number:";
 cin>>c;

 
  if(a>b && a>c) {cout<<"The max number is first number: "<<a<<endl;}

  else if(b>a && b>c)
   {cout<<"The max number is second number: "<<b<<endl;}

  else if(c>a && c>b) 
  {cout<<"The max number is third number: "<<c<<endl;}
 
 return 0;
}