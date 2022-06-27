#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  float tc,tf;

  cout<<"Enter temeprature in celcius:";
  cin>>tc;

  tf = 1.8*tc + 32 ;

  cout<<"\n Temperature in farenheit:"<<tf<<endl;

  cout<<"\nEnter temeprature in farenheit:";
  cin>>tf;

  tc = (tf - 32) * (5.0/9);

  cout<<"\n Temperature in celcius:"<<tc<<endl;

  return 0;

}