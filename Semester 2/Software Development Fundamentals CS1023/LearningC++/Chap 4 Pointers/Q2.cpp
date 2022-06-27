#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void swap(int *p1,int *p2)
{
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main()
{
  int a,b;
 cout<<"Enter two numbers:\n";
 cin>>a>>b;

 swap(&a,&b);

 cout<<"\nAfter Swapping:\n";

 cout<<a<<"\t"<<b<<endl;

 return EXIT_SUCCESS;
}