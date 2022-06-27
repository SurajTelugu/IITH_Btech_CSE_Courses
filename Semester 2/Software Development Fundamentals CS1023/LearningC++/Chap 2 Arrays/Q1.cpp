#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  unsigned n,sum=0;
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
  cout<<"\nThe elements in reverse:\n";
  for(i=n-1;i>=0;i--)
  {
    cout<<arr[i]<<"\t";
  }
  cout<<"\n\n";
  for(i=0;i<n;i++)
  {
    sum = sum + arr[i];
  }
  cout<<"Sum of elements is: "<<sum<<endl;

 return EXIT_SUCCESS;
}