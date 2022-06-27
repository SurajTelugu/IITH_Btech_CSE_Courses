#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  char word[100];
  unsigned i;

  cout<<"Enter the string:";
  fgets(word,100,stdin);

  for(i=0;word[i]!= '\0';++i){;}

cout<<"The length of string is "<<i-1<<endl;

 return EXIT_SUCCESS;
}