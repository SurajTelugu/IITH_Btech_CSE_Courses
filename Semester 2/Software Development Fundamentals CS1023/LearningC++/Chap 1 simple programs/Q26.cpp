#include <iostream>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
using namespace std;



int main()
{
  float tc,tf;
  char temp;

  cout<<"Enter\nc-Celcius to farenheit\tf-Farenheit to celcius\n";

  cout<<"Enter charecter for conversion:";
  cin>>temp;
  cout<<"\n";

if(temp == 'c')
{
  cout<<"Enter temeprature in celcius:";
  cin>>tc;

  tf = 1.8*tc + 32 ;

  cout<<"Temperature in farenheit:"<<tf<<endl;
}

else if(temp == 'f')
{
  cout<<"\nEnter temeprature in farenheit:";
  cin>>tf;

  tc = (tf - 32) * (5.0/9);

  cout<<"Temperature in celcius:"<<tc<<endl;
}
  
 return EXIT_SUCCESS;
}