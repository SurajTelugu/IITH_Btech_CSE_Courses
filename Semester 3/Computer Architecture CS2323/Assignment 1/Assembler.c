#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variable for number of commands
unsigned Num_of_commands=0; 

                       /*****C program to convert MIPS to binary*****/

//function to generate n bit integer array for given decimal
void d2b(int dec,int* bin,int n)
{
   for(int i=n-1;i>=0;i--)
   {bin[i] = dec%2;  dec = dec/2;}   
}

//function to store 6 bit char array into int binary array used in opcode function
void st6(int bin[6],char a[6])
{
   for(int i=0;i<6;i++)
   {bin[i] = a[i]-48;}
}

//function to 32 bit int array(final binary code) to char string
 void bit_32(const int* bin,char* cbin)
{
  for(int i=0;i<32;i++)
  {cbin[i] = bin[i] + '0';}
}

//function returning hexadecimal character fo corresponding binary format
char b2h(const char* bin)
{
       if(strcmp(bin,"0000")==0) return '0'; else if(strcmp(bin,"0001")==0) return '1';
  else if(strcmp(bin,"0010")==0) return '2'; else if(strcmp(bin,"0011")==0) return '3';
  else if(strcmp(bin,"0100")==0) return '4'; else if(strcmp(bin,"0101")==0) return '5';
  else if(strcmp(bin,"0110")==0) return '6'; else if(strcmp(bin,"0111")==0) return '7';
  else if(strcmp(bin,"1000")==0) return '8'; else if(strcmp(bin,"1001")==0) return '9';
  else if(strcmp(bin,"1010")==0) return 'A'; else if(strcmp(bin,"1011")==0) return 'B';
  else if(strcmp(bin,"1100")==0) return 'C'; else if(strcmp(bin,"1101")==0) return 'D';
  else if(strcmp(bin,"1110")==0) return 'E'; else if(strcmp(bin,"1111")==0) return 'F';

  else return '\0';
}

//function to convert binarycode char string to hexadecimal
void bin2hex(const char* bin,char* hex)
{
  char **bhex = (char**) calloc(8, sizeof(char*));

   for ( int k = 0; k < 8; k++ )
  {
    bhex[k] = (char*) calloc(4, sizeof(char));
  }
  int i=0,j=0;
  while(i!=32 && j<8)
  {
    bhex[j][0] = bin[i];
    bhex[j][1] = bin[i+1];
    bhex[j][2] = bin[i+2];
    bhex[j][3] = bin[i+3];
    i=i+4; j++;
  }
  
  for(int i=0;i<8;i++)
  {
    hex[i] = b2h(bhex[i]);
  }

  free(bhex);
}

//Format checking function returns specific char for corresponding format
char check_format(const char* inst)
{
  char func[6];

  for(int i=0;i<6;i++){func[i]='\0';}
  int k=0;
  while(1)
  {
    func[k] = inst[k];
    k++;
    if(inst[k]==' '){break;}
  }

  char check = '\0';

  while(1)
  {
    char rfunc[16][6] ={"add","addu","sub","subu","mult","multu","div",
    "divu","and","or","nor","xor","slt","stlu","sll","srl"};
    for(int i=0;i<16;i++)
   {
     if(strcmp(rfunc[i],func)==0){check = 'R'; break;}
   }
   if(check=='R'){break;}

   else{
     char ifunc[10][6] ={"addi","addiu","andi","ori","slti","stliu","beq","bne","lw","sw"};
     for(int i=0;i<11;i++)
     {
       if(strcmp(ifunc[i],func)==0){check = 'I'; break;}
     }
     }
    if(check=='I'){break;}

    else
    {
     char jfunc[2][4] ={"jal","j"};
     for(int i=0;i<2;i++)
    {
       if(strcmp(jfunc[i],func)==0){check = 'J'; break;}
    }
    } if(check=='J'){break;}
    
   else
   {
   if(check=='\0')
   {
     check = 'C';
   }
   }
   if(check=='C'){break;}
  }

    return check;
}

//Function to read given file and store it in 2d array (array created by memory allocation)
void readfile(FILE* fp,char** a)
{
  char f;
  f = fgetc(fp);
  int i=0,j=0;

  while(f!=EOF && f!='\0')
  {
    if(f!='\n'){a[i][j] = f; j++;}
    else {j=0; i++;} 
    f = fgetc(fp);
  }
  
  Num_of_commands = i+1;
  fclose(fp);
}

//function to get op code for specific function in a command
void getfunc(char* inst,int* func)
{
  char insc[6];
  for(int k=0;k<6;k++){insc[k]='\0';}
  int i=0;
  while(1)
  {
    insc[i] = inst[i];
    i++;
    if(inst[i]==' '){break;}
  }

  char check = check_format(inst);

if(check=='R')
{
// R format functions 
       if(strcmp(insc,"add")==0){st6(func,"100000");}  else if(strcmp(insc,"addu")==0){st6(func,"100001");}
  else if(strcmp(insc,"sub")==0){st6(func,"100010");}  else if(strcmp(insc,"subu")==0){st6(func,"100011");}
  else if(strcmp(insc,"mult")==0){st6(func,"011000");} else if(strcmp(insc,"multu")==0){st6(func,"011001");}
  else if(strcmp(insc,"div")==0){st6(func,"011010");}  else if(strcmp(insc,"divu")==0){st6(func,"011011");}
  else if(strcmp(insc,"and")==0){st6(func,"100100");}  else if(strcmp(insc,"or")==0){st6(func,"100101");}
  else if(strcmp(insc,"nor")==0){st6(func,"100111");}  else if(strcmp(insc,"xor")==0){st6(func,"100110");}
  else if(strcmp(insc,"slt")==0){st6(func,"101010");}  else if(strcmp(insc,"sltu")==0){st6(func,"101001");}
  else if(strcmp(insc,"sll")==0){st6(func,"000000");}  else if(strcmp(insc,"slr")==0){st6(func,"000010");}
}
else if(check=='I')
{
// I format functions
     if(strcmp(insc,"addi")==0){st6(func,"001000");}   else if(strcmp(insc,"addiu")==0){st6(func,"001001");}
else if(strcmp(insc,"andi")==0){st6(func,"001100");}   else if(strcmp(insc,"ori")==0){st6(func,"001101");}
else if(strcmp(insc,"slti")==0){st6(func,"001010");}   else if(strcmp(insc,"sltui")==0){st6(func,"001001");}  
else if(strcmp(insc,"beq")==0){st6(func,"000100");}    else if(strcmp(insc,"bne")==0){st6(func,"000101");}    
else if(strcmp(insc,"lw")==0){st6(func,"100011");}     else if(strcmp(insc,"sw")==0){st6(func,"101011");}    } 

else if(check=='J')
{
//J format functions 
 if(strcmp(insc,"j")==0){st6(func,"000010");}      else if(strcmp(insc,"jal")==0){st6(func,"000011");}
}
}

//function to get register number for given register
void getregnum(char* reg,int* rb)
{
       if(strcmp(reg,"$zero")==0){d2b(0,rb,5);}
  else if(strcmp(reg,"$v0")==0){d2b(2,rb,5);}  else if(strcmp(reg,"$v1")==0){d2b(3,rb,5);}

  else if(strcmp(reg,"$a0")==0){d2b(4,rb,5);}  else if(strcmp(reg,"$a1")==0){d2b(5,rb,5);}
  else if(strcmp(reg,"$a2")==0){d2b(6,rb,5);}  else if(strcmp(reg,"$a3")==0){d2b(7,rb,5);}

  else if(strcmp(reg,"$t0")==0){d2b(8,rb,5);}  else if(strcmp(reg,"$t1")==0){d2b(9,rb,5);}
  else if(strcmp(reg,"$t2")==0){d2b(10,rb,5);} else if(strcmp(reg,"$t3")==0){d2b(11,rb,5);}
  else if(strcmp(reg,"$t4")==0){d2b(12,rb,5);} else if(strcmp(reg,"$t5")==0){d2b(13,rb,5);}
  else if(strcmp(reg,"$t6")==0){d2b(14,rb,5);} else if(strcmp(reg,"$t7")==0){d2b(15,rb,5);}

  else if(strcmp(reg,"$s0")==0){d2b(16,rb,5);} else if(strcmp(reg,"$s1")==0){d2b(17,rb,5);}
  else if(strcmp(reg,"$s2")==0){d2b(18,rb,5);} else if(strcmp(reg,"$s3")==0){d2b(19,rb,5);}
  else if(strcmp(reg,"$s4")==0){d2b(20,rb,5);} else if(strcmp(reg,"$s5")==0){d2b(21,rb,5);}
  else if(strcmp(reg,"$s6")==0){d2b(22,rb,5);} else if(strcmp(reg,"$s7")==0){d2b(23,rb,5);}

  else if(strcmp(reg,"$t8")==0){d2b(24,rb,5);} else if(strcmp(reg,"$t9")==0){d2b(25,rb,5);}

  else if(strcmp(reg,"$gp")==0){d2b(28,rb,5);} else if(strcmp(reg,"$sp")==0){d2b(29,rb,5);}
  else if(strcmp(reg,"$fp")==0){d2b(30,rb,5);} else if(strcmp(reg,"$ra")==0){d2b(31,rb,5);}
}

/******************************R format binary coding function***************************/
void rformat(char* inst,char* bin_code)
{
   int* bin = (int*)(malloc)(32*sizeof(int));
   for(int i=0;i<6;i++){bin[i]=0;}    //opcode = 000000

  int* rd = (int*)(malloc)(5*sizeof(int));
  int* rs = (int*)(malloc)(5*sizeof(int));
  int* rt = (int*)(malloc)(5*sizeof(int));
  int* func = (int*)(malloc)(6*sizeof(int));
   
   getfunc(inst,func);
   for(int i=26;i<32;i++) {bin[i]=func[i-26];} 

   char insc[6];
  for(int i=0;i<6;i++){insc[i]='\0';}
  int m=0;
  while(1)
  {
    insc[m] = inst[m];
    m++;
    if(inst[m]==' '){break;}
  }

  char* crd = (char*)(malloc)(5*sizeof(char));
  char* crs = (char*)(malloc)(5*sizeof(char));
  char* crt = (char*)(malloc)(5*sizeof(char));

  //for(int l=0;l<5;l++){crd[l]='\0';}
  //for(int l=0;l<5;l++){crs[l]='\0';}
  //for(int l=0;l<5;l++){crt[l]='\0';}
   
   char* temp1 = (char*) malloc(5*sizeof(char));

   int i=0,j=0, k=0;
   // taking the value of rd(destination)
   while(1)
   {
     if(inst[i]=='$'){break;}
     i++;
   } 
   
   j=i; 

   while(1)
   {
    if(inst[j]==','){break;}
    temp1[k] = inst[j]; 
    k++; j++;
   }
  
   strcpy(crd,temp1);
   free(temp1);

   char* temp2 = (char*) malloc(5*sizeof(char));

   while(1)
   {
     if(inst[j]=='$'){break;}
     j++;
   } 
   i=j; k=0;

   while(1)
   {
     if(inst[i]==','){break;}
     temp2[k] = inst[i]; 
     k++; i++;
   }
   
   strcpy(crs,temp2);
   free(temp2);

   if(strcmp(insc,"sll")==0 ||strcmp(insc,"slr")==0)
  {
     int* shft_bin = (int*) malloc(5*sizeof(int));
     char shft[3]; for(int l=0;l<3;l++){shft[l] = '\0';}
     int len = i;
     char* temp3 = (char*) malloc(3*sizeof(char));

     while(1)
     {
       if(inst[len]!=' ' && inst[len]!=','){break;}
       len++;
     }

     k=0;

     while(1)
     {
       if(inst[len]=='\0'){break;}
       temp3[k] = inst[len];
       k++; len++;
     }
     strcpy(shft,temp3); free(temp3);

     int num = atoi(shft);  

     getregnum(crs,rs); 
     getregnum(crd,rd); 
     for(int l=0;l<5;l++){rt[l] = 0;}
     d2b(num,shft_bin,5);

     for(int i=21;i<26;i++){bin[i]=shft_bin[i-21];} //shift amount

  }
  
 else
 {
   char* temp3 = (char*) malloc(5*sizeof(char));
  
   while(1)
   {
     if(inst[i]=='$'){break;}
     i++;
   }
   j=i; k=0;

   while(1)
   {
     if(inst[j]=='\0'){break;}
     temp3[k] = inst[j]; 
     k++; j++;
   }

   strcpy(crt,temp3);
   free(temp3);
  
  getregnum(crd,rd); 
  getregnum(crs,rs); 
  getregnum(crt,rt); 

  for(int i=21;i<26;i++){bin[i]=0;} //shift amount = 00000
 }
 
  for(int i=6;i<11;i++) {bin[i]=rs[i-6];}
  for(int i=11;i<16;i++) {bin[i]=rt[i-11];}
  for(int i=16;i<21;i++) {bin[i]=rd[i-16];}
  
  bit_32(bin,bin_code);
  free(bin);  free(func); free(crd); free(crs); free(crt);
}

/******************************I format binary coding function***************************/

void iformat(char* inst,char* bin_code)
{
  int* bin = (int*)(malloc)(32*sizeof(int));

  int* rs = (int*)(malloc)(5*sizeof(int));
  int* rt = (int*)(malloc)(5*sizeof(int));
  int* op = (int*)(malloc)(6*sizeof(int));
  int* add = (int*)(malloc)(16*sizeof(int));
  
  getfunc(inst,op);
  for(int i=0;i<6;i++){bin[i]= op[i];}  //op code written 

  char insc[6];
  for(int i=0;i<6;i++){insc[i]='\0';}
  int k=0;
  while(1)
  {
    insc[k] = inst[k];
    k++;
    if(inst[k]==' '){break;}
  }

 // Case 1 : bne and beq
  if(strcmp(insc,"bne") == 0 || strcmp(insc,"beq") == 0)
  {
    char* crs = (char*)(malloc)(5*sizeof(char));
    char* crt = (char*)(malloc)(5*sizeof(char));
    char* cnum = (char*)(malloc)(5*sizeof(char));

    char* temp1 = (char*) malloc(5*sizeof(char));
  
   int i=0,j=0,k=0;
   // taking the value of rs
   while(1)
   {
     if(inst[i]=='$'){break;}
     i++;
   } 
   j=i; 
   while(1)
   {
    if(inst[j]==','){break;}
    temp1[k] = inst[j]; 
    k++; j++;
   }
  
   strcpy(crs,temp1);
   free(temp1);

   char* temp2 = (char*) malloc(5*sizeof(char));

   while(1)
   {
     if(inst[j]=='$'){break;}
     j++;
   } 
   i=j; k=0;

   while(1)
   {
     if(inst[i]==','){break;}
     temp2[k] = inst[i]; 
     k++; i++;
   }
   
   strcpy(crt,temp2);
   free(temp2);

   char* temp3 = (char*) malloc(5*sizeof(char));
  
   j=i; k=0;
   while(1)
   {
     if(inst[j]=='$'){break;}
     j++;
   } 

   while(1)
   {
     if(inst[j]=='\0'){break;}
     temp3[k] = inst[j]; 
     k++; j++;
   }

   strcpy(cnum,temp3);
   free(temp3);

   int num = atoi(cnum);  free(cnum);

   getregnum(crs,rs); free(crs);
   getregnum(crt,rt); free(crt);
   d2b(num,add,16);
   
   for(int i=6;i<11;i++)  {bin[i]= rs[i-6];}
   for(int i=11;i<16;i++) {bin[i]= rt[i-11];}
   for(int i=16;i<32;i++) {bin[i]= add[i-16];}

   bit_32(bin,bin_code);
 }
 
 // Case 2 : lw and sw
  if(strcmp(insc,"lw") == 0 || strcmp(insc,"sw") == 0)
  {
    char* crt = (char*) malloc(5*sizeof(char));
    char* crs = (char*) malloc(5*sizeof(char));
    char* cnum = (char*) malloc(5*sizeof(char));
    
   char* temp1 = (char*) malloc(5*sizeof(char));
  
   int i=0,j=0,k=0;
   // taking the value of rd(destination)
   while(1)
   {
     if(inst[i]=='$'){break;}
     i++;
   } 
   
   j=i; 

   while(1)
   {
    if(inst[j]==','){break;}
    temp1[k] = inst[j]; 
    k++; j++;
   }
  
   strcpy(crt,temp1);
   free(temp1);
   
   char* temp2 = (char*) malloc(5*sizeof(char));
   while(1)
   {
    if(inst[j]==','|| inst[j]==' ') j++;
    else break;
  }
    i=j; k=0;
  while(1)
  {
    if(inst[i]=='('){break;}
    temp2[k] = inst[i]; 
    k++; i++;
  }
  strcpy(cnum,temp2);
  free(temp2);

 char* temp3 = (char*) malloc(5*sizeof(char));
 j=i+1; k=0;
 while(1)
 {
   if(inst[j]==')'){break;}
   temp3[k] = inst[j];
   k++; j++;
 }
   strcpy(crs,temp3);
   free(temp3);

   int num = atoi(cnum); free(cnum);

   getregnum(crs,rs); free(crs);
   getregnum(crt,rt); free(crt);
   d2b(num,add,16);
   
   for(int i=6;i<11;i++)  {bin[i]= rs[i-6];}
   for(int i=11;i<16;i++) {bin[i]= rt[i-11];}
   for(int i=16;i<32;i++) {bin[i]= add[i-16];} 
  
   bit_32(bin,bin_code);
  }
  
  // Case 3 : immediate functions 
  else
  {
    char* crt = (char*) malloc(5*sizeof(char));
    char* crs = (char*) malloc(5*sizeof(char));
    char* cnum = (char*) malloc(5*sizeof(char));

   char* temp1 = (char*) malloc(5*sizeof(char));
  
   int i=0,j=0,k=0;
   // taking the value of rd(destination)
   while(1)
   {
     if(inst[i]=='$'){break;}
     i++;
   } 
   j=i; 
   while(1)
   {
    if(inst[j]==','){break;}
    temp1[k] = inst[j]; 
    k++; j++;
   }
  
   strcpy(crt,temp1);
   free(temp1);

   char* temp2 = (char*) malloc(5*sizeof(char));

   while(1)
   {
     if(inst[j]=='$'){break;}
     j++;
   } 
   i=j; k=0;

   while(1)
   {
     if(inst[i]==','){break;}
     temp2[k] = inst[i]; 
     k++; i++;
   }
   
   strcpy(crs,temp2);
   free(temp2);

   char* temp3 = (char*) malloc(5*sizeof(char));
   j=i; k=0;
   while(1)
    {
      if(inst[j]>=48 && inst[j]<=57){break;}
      j++;
    }
    
     while(inst[j]>=48 && inst[j]<=57)
    {
      temp3[k] = inst[j];
      j++; k++;
    }
   
   strcpy(cnum,temp3);
   free(temp3);

   int num = atoi(cnum); free(cnum);

   getregnum(crs,rs); free(crs);
   getregnum(crt,rt); free(crt);
   d2b(num,add,16);
   
   for(int i=6;i<11;i++)  {bin[i]= rs[i-6];}
   for(int i=11;i<16;i++) {bin[i]= rt[i-11];}
   for(int i=16;i<32;i++) {bin[i]= add[i-16];}

   bit_32(bin,bin_code);

  }
   free(rs); free(rt); 
   free(op); free(add);
   free(bin);
}

/******************************J format binary coding function***************************/

void jformat(char* inst,char* bin_code)
{
  int* bin = (int*) malloc(32*sizeof(int));
  int* add = (int*) malloc(26*sizeof(int));
  int* op  = (int*) malloc (6*sizeof(int));
  
  getfunc(inst,op);
  for(int i=0;i<6;i++){bin[i] = op[i];} free(op); //op code written 

    char* cadd = (char*) malloc(8*sizeof(char));
    char* temp = (char*) malloc(8*sizeof(char));
    int j=0,k=0;

    while(1)
    {
      if(inst[j]>=48 && inst[j]<=57){break;}
      j++;
    }
    
     while(inst[j]>=48 && inst[j]<=57)
    {
      temp[k] = inst[j];
      j++; k++;
    }

    strcpy(cadd,temp); free(temp);
    
  
    int num = atoi(cadd); free(cadd);
    d2b(num,add,26);
    for(int k=6;k<32;k++) {bin[k]= add[k-6];} 

    bit_32(bin,bin_code);

    free(bin); free(add);
  
}

/******************************MIPS to Machine language function 
                                   from above 3 functions***************************/

void mips_binary(char** a,FILE* fptr)
{
  int cmd=0;
  while(cmd<Num_of_commands)
  {

    char bin_code[32];
    for(int l=0;l<32;l++){bin_code[l]='\0';}
    
   if(check_format(a[cmd])=='C')
   {
    printf("Command not found");
   }

   else if(check_format(a[cmd])=='R')
   {
    //printf("Implement rformat function\n");
     
     char* tempbin = (char*) malloc(32*sizeof(char));
     rformat(a[cmd],tempbin);
     strncpy(bin_code,tempbin,32);

     char* hex_code = (char*) malloc(8*sizeof(char));
     
     bin2hex(bin_code,hex_code);
     fprintf(fptr,"%s",bin_code);
     fprintf(fptr,"[%s ; %s]\n",hex_code,a[cmd]);
     free(hex_code); free(tempbin);
     
   }

   else if(check_format(a[cmd])=='I')
   {
    //printf("Implement iformat function\n");
    char* tempbin = (char*) malloc(32*sizeof(char));
    iformat(a[cmd],tempbin);
    strncpy(bin_code,tempbin,32);
  
    char* hex_code = (char*) malloc(8*sizeof(char));
    bin2hex(bin_code,hex_code);
    
    fprintf(fptr,"%s",bin_code);
    fprintf(fptr,"[%s ; %s]\n",hex_code,a[cmd]);
    free(hex_code); free(tempbin);
   }

   else if(check_format(a[cmd])=='J')
   {
    //printf("Implement jformat function\n");

    char* tempbin = (char*) malloc(32*sizeof(char));
    jformat(a[cmd],tempbin);
    strncpy(bin_code,tempbin,32);
    char* hex_code = (char*) malloc(8*sizeof(char));
    bin2hex(bin_code,hex_code);
    
    fprintf(fptr,"%s",bin_code);
    fprintf(fptr,"[%s ; %s]\n",hex_code,a[cmd]);
    free(hex_code); free(tempbin);
   }

   cmd++; 
  }

}

/*********** main function************/

int main()
{
 printf("\t\tMIPS to Binary Converter\n");
 printf("------------------------------------------------------\n"); 
  /***Selection menu***/
  printf("Select a program from");
  printf("{prog1.asm,prog2.asm,prog3.asm,prog4.asm,prog5.asm}\n");
  printf("Enter Program name:");

  char prog[12];
  scanf("%s",prog);

  char **a = (char**) calloc(100, sizeof(char*));
   for ( int k = 0; k <100; k++ )
  {
    a[k] = (char*) calloc(100, sizeof(char));
  }

  FILE* fptr=NULL; // file pointer for text file 

  if(prog[4]=='1')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog1.asm","r");
    if(fp==NULL){printf("prog1.asm cannot be opened\n");}

    else
    {
       printf("prog1.asm opened successfully\n");
       
       readfile(fp,a);
       if(fptr==NULL){fptr = fopen("sample_data/prog1_bin.txt","w");}
       if(fptr==NULL){printf("prog1_bin.txt cannot be opened\n");}
       else{mips_binary(a,fptr);}
    }
  }

  else if(prog[4]=='2')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog2.asm","r");
    if(fp==NULL){printf("prog2.asm cannot be opened\n");}

    else
    {
       printf("prog2.asm opened successfully\n");
       
       readfile(fp,a);
       if(fptr==NULL){fptr = fopen("sample_data/prog2_bin.txt","w");}
       if(fptr==NULL){printf("prog2_bin.txt cannot be opened\n");}
       else{mips_binary(a,fptr);}
    }
  }

  else if(prog[4]=='3')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog3.asm","r");
    if(fp==NULL){printf("prog3.asm cannot be opened\n");}

    else
    {
       printf("prog3.asm opened successfully\n");
       
       readfile(fp,a);
       if(fptr==NULL){fptr = fopen("sample_data/prog3_bin.txt","w");}
       if(fptr==NULL){printf("prog3_bin.txt cannot be opened\n");}
       else{mips_binary(a,fptr);}
    }
  }

  else if(prog[4]=='4')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog4.asm","r");
    if(fp==NULL){printf("prog4.asm cannot be opened\n");}

    else
    {
       printf("prog4.asm opened successfully\n");
       
       readfile(fp,a);
       if(fptr==NULL){fptr = fopen("sample_data/prog4_bin.txt","w");}
       if(fptr==NULL){printf("prog4_bin.txt cannot be opened\n");}
       else{mips_binary(a,fptr);}
    }
  }

  else if(prog[4]=='5')
  {
    FILE* fp=NULL;
    fp = fopen("sample_data/prog5.asm","r");
    if(fp==NULL){printf("prog5.asm cannot be opened\n");}

    else
    {
       printf("prog5.asm opened successfully\n");
       
       readfile(fp,a);
       if(fptr==NULL){fptr = fopen("sample_data/prog5_bin.txt","w");}
       if(fptr==NULL){printf("prog5_bin.txt cannot be opened\n");}
       else{mips_binary(a,fptr);}
    }
  }

  else {printf("Invalid program name\n");} 

  free(a); fclose(fptr);


  return EXIT_SUCCESS;
}

