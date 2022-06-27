#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  unsigned cp,sp,ls_pft;
  cout<<"Enter cost price:";
  cin>>cp;
  cout<<"Enter selling price:";
  cin>>sp;

  if(sp > cp)
  {
    ls_pft = sp - cp ;
    cout<<"A profit of rs "<<ls_pft<<endl;
  }

  
  if(sp < cp)
  {
    ls_pft = cp - sp ;
    cout<<"A loss of rs "<<ls_pft<<endl;
  }

  
  if(sp == cp)
  {
    ls_pft = sp - cp ;
    cout<<"Neither profit nor loss rs "<<ls_pft<<endl;
  }
  
 return 0;
}