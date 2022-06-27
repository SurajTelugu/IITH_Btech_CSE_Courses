#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

struct xypoint_t
{
    double x;/*Abscissa or X coordinate*/
    double y;/*Ordinate or Y coordinate*/
};
typedef struct xypoint_t xypoint_t;

struct rtpoint_t
{
    double r;/*radius in polar coordinate system*/
    double t;/*angle(theta) in polar coordinate system*/
};
typedef struct rtpoint_t rtpoint_t;


int main()
{
  xypoint_t cartncoordn;
  rtpoint_t plrcoordn;

    printf("This program converts given Polar coordinates to Cartesian coordinates\n\n");
    printf("Enter the polar r coordinate:");
    scanf("%lf", &plrcoordn.r);
    printf("Enter the polar theta coordinate in degrees:");
    scanf("%lf",&plrcoordn.t);
    printf("\n");
  
   double rad_t=(PI/180)*(plrcoordn.t);
    
   cartncoordn.x=(plrcoordn.r)*(cos(rad_t));
   cartncoordn.y=(plrcoordn.r)*(sin(rad_t));

   printf("For given Polar coordinatesthe (x,y) Cartesian coordiantes are (%lf,%lf)\n",cartncoordn.x,cartncoordn.y);
  
  /*program ends*/
  return EXIT_SUCCESS;
}
