#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  unsigned days,ny,nw,nd;

  cout<<"Enter days:";
  cin>>days;

  ny = days / 365 ;
  days = days - ny*365 ;

  nw = days / 7 ;
  days = days - nw*7 ;

  nd = days;
  days = days - nd ;

  cout <<ny<<" Years "<<nw<<" Weeks "<<nd<<" Days"<<endl;

  return 0;
}