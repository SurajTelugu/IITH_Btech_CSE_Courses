#include<stdio.h>
#include<stdlib.h>

unsigned int num_char_string(char word[20])
{
 unsigned int num=0,i=0;
 for(i=0;i<20;i++)
 {
  if(word[i]!='\0'){num++;}
 }
 return num;
}

void swap_char(char *x,char *y) 
{
  char tmp;
  tmp=*x;
  *x=*y;
  *y=tmp;
}

void permute(char str[30],int n)
{
 unsigned int lnth_string,i,j; 
 lnth_string=num_char_string(str);

 if(n==1)
 {printf("%s\n",str);}

 else
 {
  for(i=0;i<n;i++)
  {
    swap_char(&str[0],&str[i]);
    permute(str,n-1);
    swap_char(&str[0],&str[i]);
   }
  }

}


int main()
{
 printf("This program permutates the given string for the first n characters\n\n");
 char str[30];
 int n;

 printf("Enter the string: ");
 scanf("%s",str);
 printf("Enter the value of n:");
 scanf("%d",&n);

permute(str,n);

/*program ends*/ 
 return EXIT_SUCCESS;
}