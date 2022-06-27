#include <iostream>
#include <math.h>

using namespace std;

void vowel_or_not (char n)
{
  if(n =='a'||n =='e'||n =='i'||n =='o'||n =='u'||
     n =='A'||n =='E'||n =='I'||n =='O'||n =='U')
  {cout<<"The charecter "<<n<<" is vowel\n";}

  else {cout<<"The charecter "<<n<<" is  consonant\n";}
}

int main()
{
 char c;
 cout<<"Enter the charecter:";
 cin>>c;

vowel_or_not(c);

 return 0;
}