#include <iostream>
#include <math.h>

using namespace std;

int main()
{
 double bsc_slry,hra,da,it,fin_sal;

 cout<<"Enter Basic salary:";
 cin>>bsc_slry;

 hra = 0.4 * bsc_slry;
 da  = 0.8 * bsc_slry;
 it  = 0.1 * bsc_slry;

fin_sal = bsc_slry + hra + da - it;

cout<<"\nThe final salary after deductions:"<<fin_sal<<endl;

return 0;
}