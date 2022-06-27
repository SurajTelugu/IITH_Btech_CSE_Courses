#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool prime_or_not(unsigned n)
{
  bool result=1;
  if(n==2){return 1;}
  if (n!=2 && n%2==0){result = 0;}
  else 
  {
   for(unsigned i=3;i<=n/2;i++)
  {
    if(n%i == 0){result = 0;}
  }
  }
  
 return result; 
}


int main()
{
  unsigned N;
  cout<<"Enter value of N:";
  cin>>N;

  if(N==0||N==1)
  {cout<<"The number is neither prime nor composite"<<endl;}

  else 
{
  bool Ans = prime_or_not(N);

  if(Ans == 0){cout<<"The number "<<N<<" is not a prime number\n";}
  else{cout<<"The number "<<N<<" is a prime number\n";}
}

 return EXIT_SUCCESS;
}