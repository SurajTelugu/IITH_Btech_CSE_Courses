#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Global variable for number of commands
unsigned Num_of_commands=0; 

// function to read binary file
void readbinfile(FILE* fp,char** a)
{
  char f;
 
 char **bin = (char**) calloc(100, sizeof(char*));
   for ( int k = 0; k <100; k++ )
  {
    bin[k] = (char*) calloc(100, sizeof(char));
  }

  f = fgetc(fp); int i=0,j=0;

  while(f!=EOF && f!='\0')
  {
    if(f!='\n'){bin[i][j] = f; j++;}
    else {j=0; i++;} 
    f = fgetc(fp);
  }
  Num_of_commands = i+1;

  for(int k=0;k<Num_of_commands;k++) 
  {strncpy(a[k],bin[k],32);}

  fclose(fp); free(bin);
}

void revstr(char *str1)  
{  
    int i, len, temp;  
    len = strlen(str1);
    for (i = 0; i < len/2; i++)  
    {    
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}

int bin_int(char* s) 
{ 
    int num = 0; 
    int n = strlen(s); 

    for (int i = n-1; i>=0; i--) 
    {num = num  + (s[i] - '0')*pow(2,(n-1)-i);} 
    return num;
} 

void bin_dec(char* bin, char* str)
{
    int num = bin_int(bin);
    int i = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
    }
    
    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }

    str[i] = '\0'; 
     revstr(str);
}

// Function to check format of given binary command
char check_format(char* a)
{
  char op[7];
  for(int i=0;i<7;i++){op[i]='\0';}
  strncpy(op,a,6);
  //printf("%s : %s\n",op,a);
  char check='\0';
  while(1)
  {
   if(strcmp(op,"000000")==0){check = 'R';}
   if(check=='R') break;

   else
   {
      char iop[10][7] ={"001000","001001","001100","001101",
      "001010","001001","000100","000101","100011","101011"};

      for(int i=0;i<11;i++)
     {
       if(strcmp(iop[i],op)==0){check = 'I'; break;}
     }
   }
   if(check=='I') break;

   else
   {
     char jop[2][7] ={"000011","000010"};

     for(int i=0;i<2;i++)
     {
       if(strcmp(jop[i],op)==0){check = 'J'; break;}
     }
   }
   if(check=='J') break;

   else
   {
     if(check=='\0'){check = 'C';}
   }
   if(check=='C'){break;}
   
  }

 return check;
}

void getfunc(char* a,char* func)
{
  char fop[7];
  for(int i=0;i<7;i++){fop[i]='\0';}
  char check  = check_format(a);
  if(check=='R')
  {for(int i=26;i<32;i++) {fop[i-26]=a[i];}}

  else{strncpy(fop,a,6);}

  // R format functions 
  if(check=='R')
  {
       if(strcmp(fop,"100000")==0){strcpy(func,"add");}  else if(strcmp(fop,"100001")==0){strcpy(func,"addu");}
  else if(strcmp(fop,"100010")==0){strcpy(func,"sub");}  else if(strcmp(fop,"100011")==0){strcpy(func,"subu");}
  else if(strcmp(fop,"011000")==0){strcpy(func,"mult");} else if(strcmp(fop,"011001")==0){strcpy(func,"multu");}
  else if(strcmp(fop,"011010")==0){strcpy(func,"div");}  else if(strcmp(fop,"011011")==0){strcpy(func,"divu");}
  else if(strcmp(fop,"100100")==0){strcpy(func,"and");}  else if(strcmp(fop,"100101")==0){strcpy(func,"or");}
  else if(strcmp(fop,"100111")==0){strcpy(func,"nor");}  else if(strcmp(fop,"100110")==0){strcpy(func,"xor");}
  else if(strcmp(fop,"101010")==0){strcpy(func,"slt");}  else if(strcmp(fop,"101001")==0){strcpy(func,"sltu");}
  else if(strcmp(fop,"000000")==0){strcpy(func,"sll");}  else if(strcmp(fop,"000010")==0){strcpy(func,"slr");}
  }
  else if(check=='I')
  {
    // I format functions
 if(strcmp(fop,"001000")==0){strcpy(func,"addi");}   else if(strcmp(fop,"001001")==0){strcpy(func,"addiu");}
else if(strcmp(fop,"001100")==0){strcpy(func,"andi");}   else if(strcmp(fop,"001101")==0){strcpy(func,"ori");}
else if(strcmp(fop,"001010")==0){strcpy(func,"slti");}   else if(strcmp(fop,"001001")==0){strcpy(func,"sltui");}  
else if(strcmp(fop,"000100")==0){strcpy(func,"beq");}    else if(strcmp(fop,"000101")==0){strcpy(func,"bne");}    
else if(strcmp(fop,"100011")==0){strcpy(func,"lw");}     else if(strcmp(fop,"101011")==0){strcpy(func,"sw");}     
  }
  else if(check=='J')
{//J format functions 
 if(strcmp(fop,"000010")==0){strcpy(func,"j");}      else if(strcmp(fop,"000011")==0){strcpy(func,"jal");}
}
}

void getregid(char* bin,char* regid)
{
  char reg[6];
  for(int i=0;i<6;i++){reg[i]='\0';}

       if(strcmp(bin,"00000")==0){strcpy(reg,"$zero");}
  else if(strcmp(bin,"00010")==0){strcpy(reg,"$v0");}  else if(strcmp(bin,"00011")==0){strcpy(reg,"$v1");}

  else if(strcmp(bin,"00100")==0){strcpy(reg,"$a0");}  else if(strcmp(bin,"00101")==0){strcpy(reg,"$a1");}
  else if(strcmp(bin,"00110")==0){strcpy(reg,"$a2");}  else if(strcmp(bin,"00111")==0){strcpy(reg,"$a3");}

  else if(strcmp(bin,"01000")==0){strcpy(reg,"$t0");}  else if(strcmp(bin,"01001")==0){strcpy(reg,"$t1");}
  else if(strcmp(bin,"01010")==0){strcpy(reg,"$t2");} else if(strcmp(bin,"01011")==0){strcpy(reg,"$t3");}
  else if(strcmp(bin,"01100")==0){strcpy(reg,"$t4");} else if(strcmp(bin,"01101")==0){strcpy(reg,"$t5");}
  else if(strcmp(bin,"01110")==0){strcpy(reg,"$t6");}   else if(strcmp(bin,"01111")==0){strcpy(reg,"$t7");}

  else if(strcmp(bin,"10000")==0){strcpy(reg,"$s0");}   else if(strcmp(bin,"10001")==0){strcpy(reg,"$s1");}
  else if(strcmp(bin,"10010")==0){strcpy(reg,"$s2");}   else if(strcmp(bin,"10011")==0){strcpy(reg,"$s3");}
  else if(strcmp(bin,"10100")==0){strcpy(reg,"$s4");}   else if(strcmp(bin,"10101")==0){strcpy(reg,"$s5");}
  else if(strcmp(bin,"10110")==0){strcpy(reg,"$s6");}   else if(strcmp(bin,"10111")==0){strcpy(reg,"$s7");}

  else if(strcmp(bin,"11000")==0){strcpy(reg,"$t8");}   else if(strcmp(bin,"11001")==0){strcpy(reg,"$t9");}

  else if(strcmp(bin,"11100")==0){strcpy(reg,"$gp");}   else if(strcmp(bin,"11101")==0){strcpy(reg,"$sp");}
  else if(strcmp(bin,"11110")==0){strcpy(reg,"$fp");} else if(strcmp(bin,"11111")==0){strcpy(reg,"$ra");}

  strcpy(regid,reg);
}

void rformat(char* a,char* rcmd)
{
  char tcmd[30];
  for(int i=0;i<30;i++){tcmd[i]='\0';}

  char* func = (char*) malloc(6*sizeof(char)); 
  getfunc(a,func);
  
  char* rs = (char*) malloc(5*sizeof(char));
  char* rt = (char*) malloc(5*sizeof(char));
  char* rd = (char*) malloc(5*sizeof(char));
  char* shft = (char*) malloc(5*sizeof(char));
  
 char temp[6];
 for(int i=0;i<6;i++){temp[i]='\0';}
  
  strncpy(temp,a+6,5); getregid(temp,rs);
  strncpy(temp,a+11,5); getregid(temp,rt);
  strncpy(temp,a+16,5); getregid(temp,rd);

  strncpy(temp,a+21,5); bin_dec(temp,shft);
  
 int len = 0;

 strncpy(tcmd,func,strlen(func)); 
 len = strlen(func); free(func);
 tcmd[len] = ' '; len = len+1;

 strncpy(tcmd+len,rd,strlen(rd)); 
 len = len + strlen(rd);
 tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

 strncpy(tcmd+len,rs,strlen(rs)); 
 len = len + strlen(rs);
 tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

if(strcmp(shft,"0")==0)
{
 strncpy(tcmd+len,rt,strlen(rt)); 
 len = len + strlen(rt);
}

else 
{
  strncpy(tcmd+len,shft,strlen(shft)); 
 len = len + strlen(shft);
}

free(rs); free(rt); free(rd); free(shft);
strncpy(rcmd,tcmd,strlen(tcmd));
}

// I format

void iformat(char* a,char* icmd)
{
  char tcmd[30];
  for(int i=0;i<30;i++){tcmd[i]='\0';}

  char* func = (char*) malloc(6*sizeof(char)); 
  getfunc(a,func);
  
  char* rs = (char*) malloc(5*sizeof(char));
  char* rt = (char*) malloc(5*sizeof(char));
  char* rnum = (char*) malloc(6*sizeof(char));
  
 // case 1 : bne or beq
  if(strncmp(a,"000100",6)==0 || strncmp(a,"000101",6)==0) 
  {
    char temp[17];
    for(int i=0;i<17;i++){temp[i]='\0';}
    
    strncpy(temp,a+6,5); getregid(temp,rs);
    strncpy(temp,a+11,5); getregid(temp,rt);
    strncpy(temp,a+16,16); bin_dec(temp,rnum);

    int len = 0;

    strncpy(tcmd,func,strlen(func)); 
    len = strlen(func);
    tcmd[len] = ' '; len = len+1;

    strncpy(tcmd+len,rs,strlen(rs)); 
    len = len + strlen(rs);
    tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

    strncpy(tcmd+len,rt,strlen(rt)); 
    len = len + strlen(rt);
    tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

    strncpy(tcmd+len,rnum,strlen(rnum)); 
    len = len + strlen(rnum);
  }

// case 2 : lw or sw
  else if(strncmp(a,"101011",6)==0 || strncmp(a,"100011",6)==0)
  {
    char temp[17];
    for(int i=0;i<17;i++){temp[i]='\0';}
    
    strncpy(temp,a+6,5); getregid(temp,rt);
    strncpy(temp,a+11,5); getregid(temp,rs);
    strncpy(temp,a+16,16); bin_dec(temp,rnum);
    //printf("%s : %lu\n",rnum,strlen(rnum));

    int len = 0;

    strncpy(tcmd,func,strlen(func)); 
    len = strlen(func);
    tcmd[len] = ' '; len = len+1;

    strncpy(tcmd+len,rt,strlen(rt)); 
    len = len + strlen(rt);
    tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

    strncpy(tcmd+len,rnum,strlen(rnum));
    len = len + strlen(rnum);
    tcmd[len] = '('; len = len+1;

    strncpy(tcmd+len,rt,strlen(rs)); 
    len = len + strlen(rs);
    tcmd[len] = ')'; len = len+1;
  }

// case 3 immediate functions
  else
  {
    char temp[17];
    for(int i=0;i<17;i++){temp[i]='\0';}
    
    strncpy(temp,a+6,5); getregid(temp,rt);
    strncpy(temp,a+11,5); getregid(temp,rs);
    strncpy(temp,a+16,16); bin_dec(temp,rnum);
    
    int len = 0;

    strncpy(tcmd,func,strlen(func)); 
    len = strlen(func);
    tcmd[len] = ' '; len = len+1;

    strncpy(tcmd+len,rt,strlen(rt)); 
    len = len + strlen(rt);
    tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

    strncpy(tcmd+len,rs,strlen(rs)); 
    len = len + strlen(rs);
    tcmd[len] = ','; tcmd[len+1]=' ';  len = len+2;

    strncpy(tcmd+len,rnum,strlen(rnum)); 
    len = len + strlen(rnum);
}

 strncpy(icmd,tcmd,strlen(tcmd));
 free(rs); free(rt); free(rnum); free(func);
 
}

void jformat(char* a,char* jcmd)
{
  char tcmd[30];
  for(int i=0;i<30;i++){tcmd[i]='\0';}

  char* func = (char*) malloc(6*sizeof(char)); 
  getfunc(a,func);
 
  char* add = (char*) malloc(9*sizeof(char));
  
  char temp[27];
  for(int i=0;i<27;i++){temp[i]='\0';}
  strncpy(temp,a+6,26); bin_dec(temp,add);
  
  int len = 0;

  strncpy(tcmd,func,strlen(func)); 
  len = strlen(func);
  tcmd[len] = ' '; len = len+1;
  
  strncpy(tcmd+len,add,strlen(add)); 
  len = len + strlen(add);
  
  strncpy(jcmd,tcmd,strlen(tcmd));
}

void binary_mips(char** a,FILE* fptr)
{
    int cmd=0;
    while(cmd<Num_of_commands)
    {
      char instr[30];
      for(int i=0;i<30;i++){instr[i]='\0';}

      if(check_format(a[cmd])=='C')
      {
         printf("Command not found\n");
      }

      else if(check_format(a[cmd])=='R')
      {
        //printf("Implement Rformat function\n");
        rformat(a[cmd],instr);
        fprintf(fptr,"%s\n",instr);
      }

      else if(check_format(a[cmd])=='I')
      {
        //printf("Implement Iformat function\n");
        iformat(a[cmd],instr);
        fprintf(fptr,"%s\n",instr);
      }

      else if(check_format(a[cmd])=='J')
      {
        //printf("Implement Jformat function\n");
        jformat(a[cmd],instr);
        fprintf(fptr,"%s\n",instr);
      }
     
     cmd++;
    }

}
  
  
  

int main() 
{
  printf("\t\tBinary to MIPS Converter\n");
 printf("------------------------------------------------------\n"); 
  printf("Select a program from\n");
  printf("{prog1_bin.txt,prog2_bin.txt,prog3_bin.txt,prog4_bin.txt,prog5_bin.txt}\n");
  printf("Enter Program name:");
  char prog[14];
  scanf("%s",prog);

  char **a = (char**) calloc(100, sizeof(char*));

  FILE* fptr=NULL; // file pointer for MIPS file 
  
  for ( int k = 0; k <100; k++ )
  {a[k] = (char*) calloc(32, sizeof(char));}

  if(prog[4]=='1')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog1_bin.txt","r");
    if(fp==NULL){printf("prog1_bin.txt cannot be opened\n");}

    else
    {
       printf("prog1_bin.txt opened successfully\n");
       readbinfile(fp,a);
       
       if(fptr==NULL){fptr = fopen("sample_data/prog1asm.txt","w");}
       if(fptr==NULL){printf("prog1asm.txt cannot be opened\n");}
       else{binary_mips(a,fptr);}
    }
  }

  if(prog[4]=='2')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog2_bin.txt","r");
    if(fp==NULL){printf("prog2_bin.txt cannot be opened\n");}

    else
    {
       printf("prog2_bin.txt opened successfully\n");
       readbinfile(fp,a);
       
       if(fptr==NULL){fptr = fopen("sample_data/prog2asm.txt","w");}
       if(fptr==NULL){printf("prog2asm.txt cannot be opened\n");}
       else{binary_mips(a,fptr);}
    }
  }

  if(prog[4]=='3')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog3_bin.txt","r");
    if(fp==NULL){printf("prog3_bin.txt cannot be opened\n");}

    else
    {
       printf("prog3_bin.txt opened successfully\n");
       readbinfile(fp,a);
       
       if(fptr==NULL){fptr = fopen("sample_data/prog3asm.txt","w");}
       if(fptr==NULL){printf("prog3asm.txt cannot be opened\n");}
       else{binary_mips(a,fptr);}
    }
  }

  if(prog[4]=='4')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog4_bin.txt","r");
    if(fp==NULL){printf("prog4_bin.txt cannot be opened\n");}

    else
    {
       printf("prog4_bin.txt opened successfully\n");
       readbinfile(fp,a);
       
       if(fptr==NULL){fptr = fopen("sample_data/prog4asm.txt","w");}
       if(fptr==NULL){printf("prog4asm.txt cannot be opened\n");}
       else{binary_mips(a,fptr);}
    }
  }

  if(prog[4]=='5')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog5_bin.txt","r");
    if(fp==NULL){printf("prog5_bin.txt cannot be opened\n");}

    else
    {
       printf("prog5_bin.txt opened successfully\n");
       readbinfile(fp,a);
       
       if(fptr==NULL){fptr = fopen("sample_data/prog5asm.txt","w");}
       if(fptr==NULL){printf("prog5asm.txt cannot be opened\n");}
       else{binary_mips(a,fptr);}
    }
  }

  free(a); fclose(fptr);
  return EXIT_SUCCESS;

}
