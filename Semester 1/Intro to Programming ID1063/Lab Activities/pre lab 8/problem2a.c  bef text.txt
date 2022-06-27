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

    printf("This program converts given Cartesian coordinates to Polar coordinates\n\n");
    printf("Enter the Cartesian X coordinate:");
    scanf("%lf", &cartncoordn.x);
    printf("Enter the Cartesian Y coordinate:");
    scanf("%lf",&cartncoordn.y);

    plrcoordn.r=sqrt(pow(cartncoordn.x,2) + pow(cartncoordn.y,2));
    plrcoordn.t=(atan(cartncoordn.y/cartncoordn.x))*(180/PI);
    printf("\n");
  

    printf("The polar coordinates (r,theta) are (%lf,%lf)", plrcoordn.r, plrcoordn.t);

 /*program ends*/
  return EXIT_SUCCESS;
}
