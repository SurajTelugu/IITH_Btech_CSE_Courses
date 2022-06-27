#include <stdio.h>
#include<stdlib.h>

struct student_record_t
{
char firstname[25],lastname[25];
int bloodgrp;
int branch;
int x;
int y;
int z;
}sdnt[1000];

int main()
{
  printf("This program takes 1000 student records and prints them\n\n");

  int i,j=0;
  char blood_group[8][15]={"A_NEGATIVE","B_NEGATIVE","AB_NEGATIVE","O_NEGATIVE","A_POSITIVE","B_POSTIVE","AB_POSITIVE","O_POSITIVE"}; 
  char branch[11][5]={"AI","BM","BT","CHE","CHY","CSE","EE","ES","MA","ME","MSME"};

  printf("Enter your values:\n");
  for(i=0;i<1000;i++)
  {
  scanf(" %s%s%d%d%d%d%d", sdnt[i].firstname,sdnt[i].lastname,&sdnt[i].bloodgrp,&sdnt[i].branch,&sdnt[i].x,&sdnt[i].y,&sdnt[i].z);
  }

  printf("\n\n");
  printf("The student record you have entered:\n");
  for(i=0;i<1000;i++)
  {
    printf("%s %s %s %s %d %d %d\n",sdnt[i].firstname,sdnt[i].lastname,blood_group[sdnt[i].bloodgrp],branch[sdnt[i].branch],sdnt[i].x,sdnt[i].y,sdnt[i].z);
  }


  /*Finding tallest person*/
 for(i=0;i<1000;i++)
 {
   if(sdnt[j].y<sdnt[i].y)
   j=i;
 }
printf("\nThe tallest person in the record:\n%s %s %s %s %d %d %d\n\n",sdnt[j].firstname,sdnt[j].lastname,blood_group[sdnt[j].bloodgrp],branch[sdnt[j].branch],sdnt[j].x,sdnt[j].y,sdnt[j].z);
printf("\n\n");

/*Finding shortest person*/
j=0;
for(i=0;i<1000;i++)
 {
   if(sdnt[j].y>sdnt[i].y)
   j=i;
 }
 printf("\nThe shortest person in the record:\n%s %s %s %s %d %d %d\n\n",sdnt[j].firstname,sdnt[j].lastname,blood_group[sdnt[j].bloodgrp],branch[sdnt[j].branch],sdnt[j].x,sdnt[j].y,sdnt[j].z);
 printf("\n\n");
 
 /*Program ends*/
return EXIT_SUCCESS;
}
