#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  float a,b,c,del,r1,r2;

  cout<<"Enter x^2 coefficient:";
  cin>>a;
  cout<<"Enter x coefficient:";
  cin>>b;
  cout<<"Enter constant:";
  cin>>c;
  cout<<"\n";

del = pow(b,2) - 4*a*c ;

if(del<0) {cout<<"Roots are imaginary\n";}

else
{
 r1 = (-b + sqrt(del))/(2*a);
 r2 = (-b - sqrt(del))/(2*a);

 if(r1==r2){cout<<"Both roots are equal and root is "<<r1<<endl;}
 else{cout<<"root 1 is "<<r1<<"\tRoot 2 is "<<r2<<endl;}

}

 return EXIT_SUCCESS;
}