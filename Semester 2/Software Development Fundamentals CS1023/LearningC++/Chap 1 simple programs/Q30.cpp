#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
 unsigned day;

 cout<<"Enter day number between 1 to 7:";
 cin>>day;
 cout<<"\n";

 switch(day)
 {
   case 1: {cout<<"It is sunday\n";}         break;
   case 2: {cout<<"It is monday\n";}         break;
   case 3: {cout<<"It is tuesday\n";}        break;
   case 4: {cout<<"It is wednesday\n";}      break;
   case 5: {cout<<"It is thursday\n";}       break;
   case 6: {cout<<"It is friday\n";}         break;
   case 7: {cout<<"It is sataurday\n";}      break;
   default : {cout<<"Wrong day number!!\n";} break;
 }
 return EXIT_SUCCESS;
}