#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define N 10 // Given N = 10 in the problem 

//Insertion sort function which returns Number of Comparisons
int insertion_sort(int arr[]) 
{
  int no_of_comparisions = 0;
  
  for(int i=1;i<N;i++)
  {
    int temp = arr[i];
    int j = i-1;
    
    while(j>=0 && arr[j]>temp)
    {
      no_of_comparisions++;
      arr[j+1] = arr[j];
      j--;
    }
    
    no_of_comparisions++;
    arr[j+1] = temp;
  }
  return no_of_comparisions;
}

//Function which prints the integer array of N elements
void printarray(int arr[])
{
  for(int i=0;i<N;i++)
  {printf("%d\t",arr[i]);}
  printf("\n");
}

//Function to swap two elements
void swap(int* a,int* b)
{
  *a = *a+*b; 
  *b = *a-*b; 
  *a = *a-*b;
}

//Function to generate random array of given GP 
void randomarray(int a,int r,int random[])
{
  for(int i=0;i<N;i++){random[i] = a*pow(r,i);}
    
  int i,j;
  srand(time(NULL));

  for(i=0;i<N-1;i++)
  {
    j = i + rand() % (N-i); //Using Fischer-Yates shuffle algorithm
    if(i!=j){swap(&random[i],&random[j]);}
  } 
}



int main() 
{
 int a,r;

 printf("Enter the Scale factor (a): ");
 scanf("%d",&a); // get Scale factor a

 printf("Enter the Common ratio (r): ");
 scanf("%d",&r); // get Common ratio r

 int asc[N],dsc[N],rand[N];
 
 if(a>0 && r>0) // Case 1 both Scale factor and Common ratio are positive
 {
    for(int i=0;i<N;i++){asc[i] = a*pow(r,i);}
    for(int i=0;i<N;i++){dsc[N-1-i] = asc[i];}
 }

 else if(a<0 && r>0) // Case 2 Scale factor is negative and Common ratio is positive
 {
    for(int i=0;i<N;i++){dsc[i] = a*pow(r,i);}
    for(int i=0;i<N;i++){asc[N-1-i] = dsc[i];}
 }

 else if(a>0 && r<0) // Case 3 both Scale factor is positive and Common ratio is negative
 {
    for(int i=0;i<N/2;i++){asc[(N/2)-i-1] = a*pow(r,2*i+1);}
    for(int i=N/2;i<N;i++){asc[i] = a*pow(r,2*(i-N/2));}
    for(int i=0;i<N;i++){dsc[N-1-i] = asc[i];}
 }

 else if(a<0 && r<0) // Case 4 both Scale factor and Common ratio are negative
 {
    for(int i=0;i<N/2;i++){dsc[(N/2)-i-1] = a*pow(r,2*i+1);}
    for(int i=N/2;i<N;i++){dsc[i] = a*pow(r,2*(i-N/2));}
    for(int i=0;i<N;i++){asc[N-1-i] = dsc[i];}
 }



 randomarray(a,r,rand); // Getting random array


 int comp;
 //Insertion Sort for Decending Order 
 printf("\nThe Decending order of GP obtained by (a,r):\n");
 printarray(dsc);
 comp = insertion_sort(dsc);
 printf("Insertion Sort took %d comparisions for decending order\n\n",comp);

//Insertion Sort Ascending Order
 printf("The Ascending order of GP obtained by (a,r):\n");
 printarray(asc);
 comp = insertion_sort(asc);
 printf("Insertion Sort took %d comparisions for ascending order \n\n",comp);

//Insertion Sort Random Order
 printf("The Random Order of GP obtained by (a,r):\n");
 printarray(rand);
 comp = insertion_sort(rand);
 printf("Insertion Sort took %d comparisions for random order\n",comp);

 return EXIT_SUCCESS;
}