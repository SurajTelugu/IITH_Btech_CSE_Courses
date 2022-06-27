#include <iostream>
#include <math.h>

using namespace std;

int main()
{
 char asci;

 cout<<"Enter the charecter:";
 cin>>asci;

 cout<<"\nNext charecter to the given charecter is: "<<char(asci+1)<<endl;

return 0;
}