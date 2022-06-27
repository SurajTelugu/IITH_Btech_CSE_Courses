#include <iostream>
#include <stdlib.h>

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

  if(a<b && a<c)
  {
    if(b<c){cout<<"Ascending order: "<<a<<" "<<b<<" "<<c<<endl;}
    else{cout<<"Ascending order: "<<a<<" "<<c<<" "<<b<<endl;}  
  } 

  if(b<a && b<c)
  {
    if(a<c){cout<<"Ascending order: "<<b<<" "<<a<<" "<<c<<endl;}
    else{cout<<"Ascending order: "<<b<<" "<<c<<" "<<a<<endl;}  
  } 

  if(c<b && c<a)
  {
    if(b<a){cout<<"Ascending order: "<<c<<" "<<b<<" "<<a<<endl;}
    else{cout<<"Ascending order: "<<c<<" "<<a<<" "<<b<<endl;}  
  } 

 return EXIT_SUCCESS;
}