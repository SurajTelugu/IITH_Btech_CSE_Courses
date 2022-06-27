#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  unsigned n,sum=0,even=0,odd=0;
  int i;
  cout<<"Enter No of elements:";
  cin>>n;
  cout<<"\n";

  unsigned arr[n];

  for(i=0;i<n;i++)
  {
    cout<<"Enter element "<<i+1<<":";
    cin>>arr[i];
  }

  for(i=0;i<n;i++)
  {
    if(arr[i]%2 ==0){even ++;}
    else {odd ++;}
  }

  cout<<"\n";
  cout<<"No of even numbers "<<even<<"\tNo of odd numbers "<<odd<<endl;

 return EXIT_SUCCESS;
}