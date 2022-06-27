#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

 struct xypoint_t
{
    double x;/*Abscissa or X coordinate*/
    double y;/*Ordinate or Y coordinate*/
}xypoint_t;

 struct rtpoint_t
{
    double r;/*radius in polar coordinate system*/
    double t;/*angle(theta) in polar coordinate system*/
}rtpoint_t;

double cartn_to_plr(double x,double y)
{
  printf("Enter the Cartesian X coordinate:");
  scanf("%lf",&xypoint_t.x);
  printf("Enter the Cartesian Y coordinate:");
  scanf("%lf",&xypoint_t.y);
  printf("\n");

  rtpoint_t.r=sqrt(pow(xypoint_t.x,2) + pow(xypoint_t.y,2));
  if(xypoint_t.x!=0) {rtpoint_t.t=atan(xypoint_t.y/xypoint_t.x)*(180/PI);}
  else {rtpoint_t.t=90;};

  return rtpoint_t.r;
  return rtpoint_t.t;
}

int main()
{
    printf("This program converts given Cartesian coordinates to Polar coordinates\n\n");
    double x,y;
    cartn_to_plr(x,y);
    printf("The Polar coordinates of given Cartesian coordinates are (%lf,%lf)\n",rtpoint_t.r,rtpoint_t.t);
    /*program end*/
    return EXIT_SUCCESS;


}