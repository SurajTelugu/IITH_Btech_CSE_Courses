int main() 
{
  /*this program spells the number given by user in words*/
 int n; 
 printf("enter the number between 1 to 999 and get it in english:");
 scanf("%d",&n);

  int hundplace;
  hundplace=n/100;
  switch(hundplace){
  case 0:printf("ZERO");break;
  case 1:printf("ONE");break;
  case 2:printf("TWO");break;
  case 3:printf("THREE");break;
  case 4:printf("FOUR");break;
  case 5:printf("FIVE");break;
  case 6:printf("SIX");break;
  case 7:printf("SEVEN");break;
  case 8:printf("EIGHT");break;
  case 9:printf("NINE");break;}
  printf(" HUNDRED");

  if(n/100!=0)
  
  {int tensplace,tens_place;
  tensplace=((n%100)-(n%10))%10;

  if(n%100>19)
  {
    printf("AND");
    switch(tensplace){
  case 2:printf("TWENTY");break;
  case 3:printf("THIRTY");break;
  case 4:printf("FOURTY");break;
  case 5:printf("FIFTY");break;
  case 6:printf("SIXTY");break;
  case 7:printf("SEVENTY");break;
  case 8:printf("EIGHTTY");break;
  case 9:printf("NINETY");break;}
  }
  if(n%100<=19)
  {
    printf("AND");
    switch(tens_place=n%100){
  case 1:printf("ONE");break;
  case 2:printf("TWO");break;
  case 3:printf("THREE");break;
  case 4:printf("FOUR");break;
  case 5:printf("FIVE");break;
  case 6:printf("SIX");break;
  case 7:printf("SEVEN");break;
  case 8:printf("EIGHT");break;
  case 9:printf("NINE");break;
  case 10:printf("TEN");break;
  case 11:printf("ELEVEN");break;
  case 12:printf("TWELVE");break;
  case 13:printf("THIRTEEN");break;
  case 14:printf("FOURTEEN");break;
  case 15:printf("FIFTEEN");break;
  case 16:printf("SIXTEEN");break;
  case 17:printf("SEVENTEEN");break;
  case 18:printf("EIGHTEEN");break;
  case 19:printf("NINETEEN");break;}

  if(n%10!=0)
  {int oneplace;
  printf("AND");
  switch(oneplace=n%10){
  case 1:printf("ONE");break;
  case 2:printf("TWO");break;
  case 3:printf("THREE");break;
  case 4:printf("FOUR");break;
  case 5:printf("FIVE");break;
  case 6:printf("SIX");break;
  case 7:printf("SEVEN");break;
  case 8:printf("EIGHT");break;
  case 9:printf("NINE");break;}
  }


 }

  } 
/*program ends*/
  return EXIT_SUCCESS;
}