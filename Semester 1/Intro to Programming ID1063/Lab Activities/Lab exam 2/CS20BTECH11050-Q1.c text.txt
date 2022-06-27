#include<stdio.h>
#include<stdlib.h>

unsigned int josephus_org(unsigned int n,unsigned int k)
{
  if(n==1) {return 1;}
  else{return (josephus_org(n-1,k)+k-1)%n+1;}
}

unsigned int josephus_prblm(unsigned int a[],unsigned int n)
{
  printf("Enter the value of n:");
  scanf("%u",&n);
 unsigned int i,last_person;
 for(i=0;i<n-1;i++)
 {
   printf("Enter value of a%u:",(i+1));
   scanf("%u",&a[i]);
 }
if(n!=1)
{
if(n==2 && a[1]%2==1){return 1;}
if(n==2 && a[1]%2==0){return 2;}
if(n>2)
{
for(i=0;i<n-1;i++)
{
 last_person=josephus_org(n,a[i]);
}
}}
 return last_person;

}






int main()
{
  printf("This program finds the number corresponding to the last person in generalised Josephus problem\n\n");
unsigned int n,a[n-1],lastperson;

lastperson=josephus_prblm(a,n);

printf("The last person is:%u",lastperson);
  
 
/*program end*/ 
 return EXIT_SUCCESS;
}