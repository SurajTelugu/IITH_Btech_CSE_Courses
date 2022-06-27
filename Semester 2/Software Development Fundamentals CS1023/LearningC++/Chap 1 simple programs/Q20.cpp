#include <iostream>
#include <math.h>

using namespace std;

void what_char (char n)
{
  if(n>='A' && n<='Z')
  {cout<<"The charecter "<<n<<" is Upper case alphabet\n";}

else if(n>='a' && n<='z')
  {cout<<"The charecter "<<n<<" is Lower case alphabet\n";}
  
else if(n>='1' && n<='9')
  {cout<<"The charecter "<<n<<" is Digit number\n";}

else 
{cout<<"The charecter "<<n<<" is special charecter\n";}
}

int main()
{
 char c;
 cout<<"Enter the charecter:";
 cin>>c;

what_char(c);

 return 0;
}