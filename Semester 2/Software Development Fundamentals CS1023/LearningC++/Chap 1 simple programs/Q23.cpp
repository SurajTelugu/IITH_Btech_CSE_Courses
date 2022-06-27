#include <iostream>
#include <stdlib.h>

using namespace std;



int main()
{
 int m1,m2,m3,avg_mark;

 cout<<"Enter marks in first subject:";
 cin>>m1;

 cout<<"Enter marks in second subject:";
 cin>>m2;

 cout<<"Enter marks in third subject:";
 cin>>m3;

avg_mark= (m1+m2+m3)/3;

if(avg_mark>=90)
{cout<<"\nAvg marks are "<<avg_mark<<" A grade"<<endl;}

if(avg_mark<90 && avg_mark>=75)
{cout<<"\nAvg marks are "<<avg_mark<<" B grade"<<endl;}

if(avg_mark<70 && avg_mark>=60)
{cout<<"\nAvg marks are "<<avg_mark<<" C grade"<<endl;}

if(avg_mark<60 && avg_mark>=50)
{cout<<"\nAvg marks are "<<avg_mark<<" D grade"<<endl;}

if(avg_mark<50)
{cout<<"\nAvg marks are "<<avg_mark<<" F grade failed"<<endl;}
  

 return EXIT_SUCCESS;
}