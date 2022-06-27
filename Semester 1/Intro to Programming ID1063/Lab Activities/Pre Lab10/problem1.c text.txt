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
void dedup_string(char word[20])
{
  printf("Enter the word:");
  scanf("%s",word);
 unsigned int i,j,n,k;
 n=num_char_string(word);
 for(i=0;i<n;i++)
 {
   for(j=i+1;word[j]!='\0';j++)
   {
     if(word[i]==word[j])
     {
         for(k=j;word[k]!=0;k++){word[k]=word[k+1];}
     }
   }


 }

 printf("The letters used to form the word are: %s\n",word);
}

 int main()
{
  printf("This program removes the duplicate letters in the given word and prints the letters used to form the word\n\n");
  printf("Make sure the number of characters in word should be less than 20(do not use spaces)\n");
  char string[20];
  dedup_string(string);

/*program ends*/
 return EXIT_SUCCESS;
}
