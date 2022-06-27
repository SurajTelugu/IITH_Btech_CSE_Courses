#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  int n,p=0,neg=0,zero=0;
  int i;
  cout<<"Enter No of elements:";
  cin>>n;
  cout<<"\n";

  int arr[n];

  for(i=0;i<n;i++)
  {
    cout<<"Enter element "<<i+1<<":";
    cin>>arr[i];
  }

  for(i=0;i<n;i++)
  {
    if(arr[i] > 0){p ++;}
    else if(arr[i] < 0) {neg ++;}
    else if (arr[i] == 0){zero ++;}
  }

  cout<<"\n";
  cout<<"No of positive numbers "<<p<<"\tNo of negative numbers "<<neg<<"\tNo of zeros "<<zero<<endl;

 return EXIT_SUCCESS;
}