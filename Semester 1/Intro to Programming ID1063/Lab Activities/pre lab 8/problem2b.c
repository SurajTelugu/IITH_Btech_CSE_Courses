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

double plr_to_cartn(double r,double t)
{
  printf("Enter the Polar coordinate radius(r):");
  scanf("%lf",&rtpoint_t.r);
  printf("Enter the Polar coordinate theta in degrees:");
  scanf("%lf",&rtpoint_t.t);
  printf("\n");

  double a=(rtpoint_t.t)*(PI/180);
  if(a!=PI/2){xypoint_t.x=rtpoint_t.r*(cos(a));}
  else{xypoint_t.x=0;}
  xypoint_t.y=rtpoint_t.r*(sin(a));

  return xypoint_t.x;
  return xypoint_t.y;
}

int main()
{
    printf("This program converts given Polar coordinates to Cartesian coordinates\n\n");
    double r,t;
    plr_to_cartn(r,t);

    printf("The Cartesian coordinates of given Polar coordinates are (%lf,%lf)\n",xypoint_t.x,xypoint_t.y);
    /*program end*/
    return EXIT_SUCCESS;


}



