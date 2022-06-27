#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int readSentence(char a[])
{     int i=0;
     while(1)
     {   
         a[i]=getchar();
         if (a[i]=='\n')
         break;
         i++;
     }
     return strlen(a);
}

bool check(char a[],int l)
{    
    bool alpha[27]={false};
    
        for (int i=0;i<l-1;i++)
        {
            char letter=tolower(a[i]);
            
            switch (letter) {
                
                case 'a':alpha[1]=true; break;
                case 'b':alpha[2]=true; break;
                case 'c':alpha[3]=true; break;
                case 'd':alpha[4]=true; break;
                case 'e':alpha[5]=true; break;
                case 'f':alpha[6]=true; break;
                case 'g':alpha[7]=true; break;
                case 'h':alpha[8]=true; break;
                case 'i':alpha[9]=true; break;
                case 'j':alpha[10]=true; break;
                case 'k':alpha[11]=true; break;
                case 'l':alpha[12]=true; break;
                case 'm':alpha[13]=true; break;
                case 'n':alpha[14]=true; break;
                case 'o':alpha[15]=true; break;
                case 'p':alpha[16]=true; break;
                case 'q':alpha[17]=true; break;
                case 'r':alpha[18]=true; break;
                case 's':alpha[19]=true; break;
                case 't':alpha[20]=true; break;
                case 'u':alpha[21]=true; break;
                case 'v':alpha[22]=true; break;
                case 'w':alpha[23]=true; break;
                case 'x':alpha[24]=true; break;
                case 'y':alpha[25]=true; break;
                case 'z':alpha[26]=true; break;
            }
            
           
            
            
        }
        for (int i=1;i<26;i++)
            {
                if (alpha[i]);
                else return false;
            }
        
        return true;
}

int main()
{  printf("This program checks whether given sentence is a panagram or not\n\n");
   char array[200];
   int length=0;
   bool what=false;

   length=readSentence(array);
     
   what=check(array,length);   
    
   if (what) {printf("Yes,the Sentence is a Panagram\n");}
   else {printf("No,the Sentence is not a Panagram\n");}

return EXIT_SUCCESS;
}