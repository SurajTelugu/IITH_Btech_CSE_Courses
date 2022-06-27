#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initiating Linked list for Songs (minimum length = 15 characters) 
struct node
{
  char data[15];
  struct node *next;
};  

//Defining structpointer as type SONG
typedef struct node* SONG;
//intitating global Song Linked list
SONG L = NULL; 

//Storing songs by creating Linkedlist of songs
void Store(char k[15])
{
  SONG T = (struct node*) malloc(sizeof(struct node));
  strcpy(T->data,k); // Copying Data into Linked list
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

//Function to check whether the song is present in the linked list or not 
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

//Function which returns the Linked list pointer of the given input song (we execute only if song is present)
SONG search(SONG LL,char k[15])
{
  while(LL!=NULL)
  {
    if(!strcmp(LL->data,k)){return LL;}
    LL=LL->next;
  } 
}

//Defining Queue for Playlist
struct queue
{
  int f;
  int r;
  int size;
  SONG a[100];
}; 

//Intiating global Queue variable Q for playlist
struct queue Q;

//Enqueue function 
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

//Dequeue functionwhich returns the Linked list pointer of song dequeued
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
    else {Q.f=(Q.f+1)%Q.size;}
    return temp;
  }

  else {return NULL;}
}

//Defining Stack
struct stack
{
  int top,size;
  SONG a[100];
};

//Intiating global stack variable S for recently played
struct stack S;

//Push function stores the recently played song in stack
void push(SONG LL)
{
  if(S.top!=S.size-1)
  {
    S.top++;
    S.a[S.top]=LL;
  }
}

//Pop function returns Linked list pointer of song popped
SONG pop()
{
  if(S.top!=-1)
  {
    SONG temp = S.a[S.top];
    S.top=S.top-1;
    return temp;
  }
  else return NULL; 
}

//Defining Temporary Queue for updating recently played (stacks)
struct tempq
{
  int f;
  int r;
  int size;
  SONG a[100];
};
//Initating global Temporary Queue variable tempQ
struct tempq tempQ;

//Enqueue function for tempQ
void entempq(SONG LL)
{
  if((tempQ.r+1) % tempQ.size!= tempQ.f)
  {
    if(tempQ.f==-1){tempQ.f=0,tempQ.r=0;}
    else
    {
      tempQ.r=(tempQ.r+1) % tempQ.size;
    }

    tempQ.a[tempQ.r]= LL;
  }
  else {printf("Playlist is Full\n");}
}

//Dequeue function of tempQ returns Linked list pointer of song dequeued 
SONG detempq()
{
  if(tempQ.f>-1)
  {
    SONG temp;
    temp=tempQ.a[tempQ.f];
    if(tempQ.f==tempQ.r)
    {
      tempQ.f=-1,tempQ.r=-1;
    }
  else {tempQ.f=(tempQ.f+1)%tempQ.size;}
  return temp;
  }
  else {return NULL;}
}

int main()
{
  char song[15];

  printf("Enter all songs (as strings), End with -1\n");

    while(1)
  {
    fgets(song,15,stdin);
    if(song[0]=='-' && song[1]=='1') {break;} //End if -1 condition

    Store(song);
  }

  printf("All songs entered!\n\n");
  
  // Intial Values for Playlist Queue and Temporary Queue 
  Q.f=-1;         tempQ.f=-1;  
  Q.r=-1;         tempQ.r=-1;
  Q.size =100;    tempQ.size=100;

//Inital values for Recently played songs Stack
  S.top=-1;
  S.size=100;

  printf("Create playlist, End with -1\n");
  while(1)
  {
    fgets(song,15,stdin); //Reads the char array 
    if(song[0]=='-' && song[1]=='1') {break;} //end if -1 condition

    if(ispresent(L,song)) // Checking whether song is present in Linked list
    {
      enqueue(search(L,song)); //If present enqueueing the song pointer into playlist 
      printf("Found, Enqueued\n");
    }
    else
    {
      printf("Not found in the song library\n");
    }
  }

 printf("Playlist Ready!\n\n");
 
 char Menu[3];
 while(1)
 {
   printf("Play next song, previous songs or end? n/p:k/e\n");
   scanf("%s",Menu);

   if(Menu[0]=='n')
   {
     SONG temp = dequeue(); //Playing the song in playlist by dequeueing
     if(temp!=NULL)
     {printf("Playing %s\n",temp->data);
      push(temp); // Pushing the played song into recently played stack
     }
     else
     {printf("Playlist Ended\n");}
   }

   else if(Menu[0]=='p' && Menu[1]==':')
   {
     int k = (int)Menu[2]-48; //Finding the number associated with previous songs
     SONG temp1;
     for(int i=k;i>0;i--)
     {
       if(S.top==-1)
      {printf("There aren't %d previous songs\n",k); break;}

      else
      {
        temp1=pop();
        printf("Playing %s",temp1->data);
        entempq(temp1); //Enqueueing the song played from recently played song stack into temporary queue
      }
     }
     while(tempQ.f!=-1 && tempQ.r!=-1)
      {
        push(detempq()); // Updating the recently played song stack by pushing the dequeued tenporary queue
      }
    }
 else if(Menu[0]=='e'){break;}

 else{printf("Command not found");} 
 }
  
 printf("\nBye\n");
 return EXIT_SUCCESS;
}