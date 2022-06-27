#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void multiply(void* a , void* b){

*(double *)a = (*(double *)a) * (*(double *)b);
}

int length(char* s){
    int count = 0 ;
     while(s[count] != '\0'){
         count++;
     }
     return count;
}

void concat(void* str1 , void* str2){
char* s1 = (char*)str1;
char* s2 = (char*)str2;

for( int i =length(str1) , j=0  ; j <= length(str2); i++,j++){
s1[i] = s2[j];
}

str1 = (void*)s1;
str2 = (void*)s2;

}


void iterateFunction(void (*f)(void * , void * ) , unsigned d , void *x  , void *y){
for(int i = 0 ; i<d; i++){
    (*f)(x,y);
}
}

int main()
{
 double a ,b;
 printf("Enter two no.s a and b to find a to the power b: \n");
 scanf("%lf  %lf" , &a , &b);
   double res=1;
 iterateFunction(multiply , b ,&res , &a );
 printf("Value by function is %lf and by inbuilt funtion is %lf \n" , res , pow(a,b));
 
 
char s1[] ="YA"; 
char s2[] = "HOO";
iterateFunction(concat , 3 , (void*)s1 , (void*)s2);
printf("%s \n" , s1);
  
/*program end*/ 
 return EXIT_SUCCESS;
}