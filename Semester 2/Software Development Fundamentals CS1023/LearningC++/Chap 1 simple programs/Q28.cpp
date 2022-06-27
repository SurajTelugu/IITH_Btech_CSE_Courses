#include <iostream>
#include <stdlib.h>

using namespace std;

bool leap_or_not(unsigned year)
{
  if(year%100 ==0)
  {
    if(year%400 ==0){return 1;}
    else {return 0;}
  }

  else if(year%4 == 0)
 {return 1;}
  else           
 {return 0;}

}


int main()
{
  unsigned dd,mm,yy;

  cout<<"Enter the date in format of dd mm yyyy\n";
  cin>>dd>>mm>>yy;

  if(leap_or_not(yy) == 0)
  {
    if(mm>12 || mm==0) {cout<<"Invalid date\n";}

    else
    {
      if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
      {
        if(dd>31 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
      else if(mm==4||mm==6||mm==9||mm==11)
      {
        if(dd>30 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
      else if(mm==2)
      {
        if(dd>28 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
    }
  }
  
  else if(leap_or_not(yy) == 1)
  {
    if(mm>12 || mm==0) {cout<<"Invalid date\n";}

    else
    {
      if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
      {
        if(dd>31 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
      else if(mm==4||mm==6||mm==9||mm==11)
      {
        if(dd>30 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
      else if(mm==2)
      {
        if(dd>29 || dd==0) {cout<<"Invalid date\n";}
        else {cout<<"Valid date\n";}
      }
    }
  }
  

 return EXIT_SUCCESS;
}