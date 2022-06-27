#include<stdio.h>
#include<stdlib.h> 
 struct complex
{
  double real;
  double imaginary;
};
typedef struct complex complex;

complex sum_complex(complex x,complex y)
{
  complex sum;
 printf("enter the value of real part of first complex number:");
 scanf("%lf",&x.real);
 printf("enter the value of imaginary part of first complex number:");
 scanf("%lf",&x.imaginary);
 printf("enter the value of real part of first complex number:");
 scanf("%lf",&y.real);
 printf("enter the value of imaginary part of first complex number:");
 scanf("%lf",&y.imaginary);
 printf("\n");

 sum.real=x.real+y.real;
 sum.imaginary=x.imaginary+y.imaginary;
 
 return sum;
}

complex product_complex(complex x,complex y)
{
  complex product;
 printf("enter the value of real part of first complex number:");
 scanf("%lf",&x.real);
 printf("enter the value of imaginary part of first complex number:");
 scanf("%lf",&x.imaginary);
 printf("enter the value of real part of first complex number:");
 scanf("%lf",&y.real);
 printf("enter the value of imaginary part of first complex number:");
 scanf("%lf",&y.imaginary);
 printf("\n");

 product.real=x.real*y.real - x.imaginary*y.imaginary;
 product.imaginary=x.real*y.imaginary + x.imaginary*y.real;

 return product;
}

complex address_complex(complex *c)
{
  complex p=*c;
  return p;
}



int main()
{
  //sum of complex numbers
 printf("This program prints sum of two complex numbers\n\n");
 complex x,y,sum;
 sum=sum_complex(x,y);
 printf("Sum of complex numbers is %lf+i%lf\n\n",sum.real,sum.imaginary);
 //product of complex numbers
  printf("This program prints product of two complex numbers\n\n");
 complex a,b,product;
 product=product_complex(a,b);
 printf("Product of complex numbers is %lf+i%lf\n\n",product.real,product.imaginary);
 //addresses,real,complex parts
 printf("This program prints address of complex value and accepts real and complex values\n\n");
 complex c,p;
 p=address_complex(&c);
 printf("The complex number address is:%lf+i%lf\n\n",c.real,c.imaginary);

/*program ends*/ 
 return EXIT_SUCCESS;
}