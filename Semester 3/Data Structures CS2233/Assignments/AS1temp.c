#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char data[15];
  struct node *next;
};

typedef struct node* SONG;
SONG L = NULL;

void storeLL(char k[15])
{
  SONG T = (struct node*) malloc(sizeof(struct node));
  strcpy(T->data,k);
  T->next = NULL;
 if(L==NULL) {L=T;}
 else
  {
  SONG Y=L;
  while(Y->next!=NULL)
  {Y=Y->next;}
  Y->next = T;
  }
}
/****To check whether linked list is created or not****
void printLL(SONG L)
{
  while(L!=NULL)
  {
    printf("%s",L->data);
    L=L->next;
  }
}
*/

int ispresent(SONG LL,char k[15])
{
  while(LL!=NULL)
  {
  if(!strcmp(LL->data,k))
  return 1;
  LL=LL->next;
  }
  return 0;
}

SONG search(SONG LL,char k[15])
{
  while(LL!=NULL)
  {
    if(!strcmp(LL->data,k))return LL;
    LL=LL->next;
  }
}

struct queue
{
  int f;
  int r;
  int size;
  SONG a[100];
}; 

struct queue Q;

void enqueue(SONG LL)
{
  if((Q.r+1) % Q.size!= Q.f)
  {
    if(Q.f==-1){Q.f=0,Q.r=0;}
    else
    {
      Q.r=(Q.r+1) % Q.size;
    }

    Q.a[Q.r]= LL;
  }
  else {printf("Playlist is Full\n");}
}

SONG dequeue()
{
  if(Q.f>-1)
  {
    SONG temp;
    temp=Q.a[Q.f];
    if(Q.f==Q.r)
    {
      Q.f=-1,Q.r=-1;
    }
    else Q.f=(Q.f+1)%Q.size;
    return temp;
  }
}

struct stack
{
  int top,size;
  SONG a[100];
};

struct stack S;

void push(SONG LL)
{
  if(S.top!=S.size-1)
  {
    S.top++;
    S.a[S.top]=LL;
  }
}

SONG pop()
{
  if(S.top!=-1)
  {
    SONG temp = S.a[S.top];
    S.top=S.top-1;
    return temp;
  }
  else{printf("Sorry!, There were no recent songs");}  
}




int main()
{
  char song[15];

  printf("Enter all songs (as strings), End with -1\n");

    while(1)
  {
    fgets(song,15,stdin);
    if(song[0]=='-' && song[1]=='1') {break;}

    storeLL(song);
  }

  printf("All songs entered!\n\n");
  //printLL(L);
  
  Q.f=-1;
  Q.r=-1;
  Q.size =100;

  printf("Create playlist, End with -1\n");
  while(1)
  {
    fgets(song,15,stdin);
    if(song[0]=='-' && song[1]=='1') {break;}

    if(ispresent(L,song))
    {
      enqueue(search(L,song));
      printf("Found, Enqueued\n");
    }
    else
    {
      printf("Not found in the song library\n");
    }
  }

 printf("Playlist Ready!\n\n");
 printf("%s",dequeue()->data);
  
 return EXIT_SUCCESS;
}