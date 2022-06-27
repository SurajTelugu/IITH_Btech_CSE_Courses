#include <iostream>
#include <stdlib.h>

using namespace std;



int main()
{
 float a,b;
 char op;

 cout<<"Enter first number:";
 cin>>a;

 cout<<"Enter second number:";
 cin>>b;

cout<<"\nWe can perform 4 operations\n + = addition\t - = subtraction\t * = multplication\t / = division\n";

cout<<"\nEnter the operation symbol:";
cin>>op;

if(op == '+'){cout<<"\n"<<a+b<<endl;}
else if(op == '-'){cout<<"\n"<<a-b<<endl;}
else if(op == '*'){cout<<"\n"<<a*b<<endl;}
else if(op == '/'){cout<<"\n"<<a/b<<endl;}
else {cout<<"Invalid operation"<<endl;}

 return EXIT_SUCCESS;
}