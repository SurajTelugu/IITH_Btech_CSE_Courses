#include <iostream>
#include <math.h>

using namespace std;

void even_or_odd (unsigned n)
{
  if(n%2 == 0){cout<<"The number "<<n<<" is even\n";}
  else {cout<<"The number "<<n<<" is odd\n";}
}

int main()
{
 unsigned num;
 cout<<"Enter the number:";
 cin>>num;

 even_or_odd(num);
 
 return 0;
}