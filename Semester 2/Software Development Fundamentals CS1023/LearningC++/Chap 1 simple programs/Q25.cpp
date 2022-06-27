#include <iostream>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
using namespace std;



int main()
{
 char fig;
 float area;

 cout<<"Caluclating Area of Figures\n";
 cout<<"Enter\ns for Square \t r for rectangle \t c for circle \t t for triangle\n";

 cout<<"\nEnter respective charecter for figure:";
 cin>>fig;
cout<<"\n";

 if(fig == 's')
 {
   float side;
   cout<<"Enter the side length:";
   cin>>side;
   area = side * side ;
   cout<<"Area of square is "<<area<<endl;
 }

 else if(fig == 'r')
 {
   float l,b;
   cout<<"Enter length:";
   cin>>l;
   cout<<"Enter breadth:";
   cin>>b;
   area = l * b ;
   cout<<"Area of rectangle is "<<area<<endl;
 }

 else if(fig == 'c')
 {
   float r;
   cout<<"Enter radius:";
   cin>>r;
   area =  PI * r * r ;
   cout<<"Area of circle is "<<area<<endl;
 }

 else if(fig == 't')
 {
   float s1,s2,s3,s;
   cout<<"Enter side 1:";
   cin>>s1;
   cout<<"Enter side 2:";
   cin>>s2;
   cout<<"Enter side 3:";
   cin>>s3;
   s = (s1+s2+s3)/2;
   area = sqrt(s*(s-s1)*(s-s2)*(s-s3));
   cout<<"Area of triangle is "<<area<<endl;
 }

 return EXIT_SUCCESS;
}