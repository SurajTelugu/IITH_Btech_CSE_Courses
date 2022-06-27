#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 FILE* f;
 char* arr[20][1000];

 if (f==NULL) {printf("File cannot be read\n");}

else
{
  fopen("1000commonwords.txt","a");
  for(int i=0;i<1000;i++)
  {
    fscanf(f,"%s\n",arr[20][i]);
  }
}
fclose(f);

for(int i=0;i<1000;i++)
{
  if(strlen(arr[20][i])==7)
  {
    printf("%s",arr[20][i]);
  }
}

return EXIT_SUCCESS;
}
