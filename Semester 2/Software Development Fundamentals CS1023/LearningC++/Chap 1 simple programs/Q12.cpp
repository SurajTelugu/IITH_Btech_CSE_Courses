#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  unsigned amnt,n500,n100,n5,n20,n10,n2;

  cout<<"Enter amount:";
  cin>>amnt;

  n500 = amnt/500;
  amnt = amnt - n500*500;

  n100 = amnt/100;
  amnt = amnt - n100*100;

  n20 = amnt/20;
  amnt = amnt - n20*20;

  n10 = amnt/10;
  amnt = amnt - n10*10;

  n5 = amnt/5;
  amnt = amnt - n5*5;

  n2 = amnt/2;
  amnt = amnt - n2*2;

  cout<<"NO of 500 notes:"<<n500<<"\tNO of 100 notes:"<<n100<<endl;
  cout<<"NO of 20 notes:"<<n20<<"\tNO of 10 notes:"<<n10<<endl;
  cout<<"NO of 5 coins:"<<n5<<"\t\tNO of 2 coins:"<<n2<<endl;
  
return 0;
}