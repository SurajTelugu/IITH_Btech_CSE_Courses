#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  unsigned year;

  cout<<"Enter the year:";
  cin>>year;

  if(year%100 ==0)
  {
    if(year%400 ==0){cout<<"The given year is a century leap year\n";}
    else {cout<<"The given year is a century year but not a leap year\n";}
  }

  else if(year%4 == 0)
 {cout<<"The given year is a leap year"<<endl;}
  else           
 {cout<<"The given year is a not leap year"<<endl;}

 return EXIT_SUCCESS;
}