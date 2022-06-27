#include <stdio.h>
#include<stdlib.h>

int main() 
{
 /*this program gives the n! upto 1000 numbers*/
 int n,i;
 printf("enter a number from 1 to 1000 to find its factorial:");
 scanf("%d",&n);

 int fact[1000000]={0};
 fact[0]=1;

 int j,k=0,l=0;

 printf("the value of factorial of n:\n");

 for(i=2;i<=n;i++)
 {
   for(j=0;j<=k;j++) { fact[j]*=i;}

   for(j=0;j<=k;j++) 
   {
     if(fact[j]>9&&j<k)
     {
       fact[j+1]+=fact[j]/10;
       fact[j]=fact[j]%10;
     }

     else if(fact[j]>9)
     {
       k++;
       fact[j+1]=fact[j]/10;
       fact[j]=fact[j]%10;
     }
   }
 }

 for(i=k;i>=0;i--)
 printf("%d",fact[i]);
 
/*program ends*/
  return EXIT_SUCCESS;
}