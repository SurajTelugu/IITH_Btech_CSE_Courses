#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating Node for Binary search tree
struct BstNode
{
    char key[15];
    struct BstNode *left, *right;
};
typedef struct BstNode BstNode;

//Initializing global Binary search tree pointer 
BstNode* root=NULL;

//Function to create New Node for BST 
BstNode* newNode(char* song)
{
  root = (BstNode*) malloc(sizeof(BstNode));
  strcpy(root->key,song);
  root->left = root->right = NULL;
  return root;
}

//Function to insert Char array song into Binary search tree
BstNode* insert(BstNode* r, char* song)
{
 if(song!=NULL)  
 {   if(r==NULL)
        r = newNode(song); //Creating newnode 
  
 //Searching place to insert node
 else if(strcmp(song,r->key)>0) // root->key comes first in  lexicographic order. Insertion to right
    {    
      r->right = insert(r->right,song);
    }
 else if(strcmp(song,r->key)<0) // song comes first in  lexicographic order. Insertion to left
    {
      r->left = insert(r->left,song);
    }
  else if(strcmp(r->key,song)==0) // Already existed song cannot be inserted to Library
    {printf("Error song already exist\n");}
 }

  return r;
}

BstNode* search(BstNode* r,char* song)
{
    if(r==NULL)
    {printf("Song not found in library\n");
     return NULL;}
     if(strcmp(r->key,song)==0) return r;
     if(strcmp(song,r->key)<0) // song comes first in  lexicographic order, search the left subtree
    {return search(r->left,song);}
    else 
    {return search(r->right,song);} //root->key comes first in  lexicographic order,search the right subtree
    
}

BstNode* find_minimum(BstNode* node)
{
    BstNode* current = node;
    //loop down to find the element which comes first in lexicographic order
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

BstNode* deleteNode(BstNode* r,char* song)
{
    // base case
    if (r == NULL)
        return r;
 
    // song to be deleted find its lexicographic postion
    // If song comes first in lexicographical order than r->key, then it lies in left subtree
    if (strcmp(song,r->key)<0)
        r->left = deleteNode(r->left,song);
 // If r->key comes first in lexicographical order than song, then it lies in right subtree
    else if (strcmp(song,r->key))
        r->right = deleteNode(r->right,song);
 
    // if song is same as root's key,
    // then This is the node to be deleted
    else {
        // node with only one child or no child:
        if (r->left == NULL) {
            BstNode* temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL) {
            BstNode* temp = r->left;
            free(r);
            return temp;
        }
 
        // node with two children:
        // Getting the lexicographically least in the right subtree using find_minimum
        BstNode* temp = find_minimum(r->right);
        // Copy the temp's content to this node
        strcpy(r->key,temp->key);
        // Delete the inorder successor
        r->right = deleteNode(r->right, temp->key);
    }
    return r;
}

//Printing Function of Binary Search tree 
void preorder(BstNode* T)
{
 if (T!=NULL) 
{
  printf("%s\n", T->key); 
    preorder(T->left);
    preorder(T->right);
}
}

/*****Library Created with Binary Search Tree using above functions successfully*****/

// Create Node for AVL Tree
struct AvlNode 
{
  char key[15];
  struct AvlNode *left;
  struct AvlNode *right;
  int height;
};
typedef struct AvlNode AvlNode;
AvlNode* Playlist=NULL; //Creating s global AvlNode pointer,Call it Playlist

int max(int a, int b) {return (a > b) ? a : b;} //max function used in deleteAvlNode function

// Function to Calculate height of node
int height(AvlNode* N) 
{
  if (N == NULL)
    return 0;
  return N->height;
}

// Dunction to Create an Avlnode
AvlNode* AvlnewNode(char* song) 
{
  Playlist = (AvlNode*)malloc(sizeof(AvlNode));
  strcpy(Playlist->key,song);
  Playlist->left = Playlist->right = NULL;
  Playlist->height = 1;
  return (Playlist);
}

// Right rotate function used in deleteAvlNode function
AvlNode* rightRotate(AvlNode* y) 
{
  AvlNode* x = y->left;
  AvlNode* T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate used in deleteAvlNode function
AvlNode* leftRotate(AvlNode* x) 
{
  AvlNode* y = x->right;
  AvlNode* T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

//Function to get the balance factor of given node
int getBalance(AvlNode* N) 
{
  if (N == NULL)
    return 0;
  return (height(N->left) - height(N->right));
}

// Insertion of songs into playlist(inserting songs in AVL Tree node)
AvlNode* insertNode(AvlNode* n,char* song)
 {
  // Finding the correct position to insertNode the node and inserting Node in it
  if (n == NULL)
    return (AvlnewNode(song));

  if (strcmp(song,n->key)<0)
    n->left = insertNode(n->left,song);
  else if (strcmp(song,n->key)>0)
    n->right = insertNode(n->right,song);
  else
    return n;

  n->height = 1 + max(height(n->left), height(n->right)); //Updating heights of each node 
 
 // Balancing the tree using rotate functions at appropriate conditions
  int balance = getBalance(n);
  if (balance > 1 && strcmp(song,n->left->key)<0)    //Left-Left imbalance
    return rightRotate(n); 

  if (balance < -1 && strcmp(song,n->right->key)>0)  //Right-Right imbalance
    return leftRotate(n);

  if (balance > 1 && strcmp(song,n->left->key)>0)   //Left-Right imbalance
  {
    n->left = leftRotate(n->left);
    return rightRotate(n);
  }

  if (balance < -1 && strcmp(song,n->right->key)<0) //Right-Left imbalance
  {
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }

  return n;
}

//Function to print the Playlist in preorder traversal
void Avlpreorder(AvlNode* T)
{
 if (T!=NULL) 
{
  printf("%s\n", T->key); 
    Avlpreorder(T->left);
    Avlpreorder(T->right);
}
}

//Function to find element the first in lexographic order in AVL tree 
AvlNode* minAvlNode(AvlNode *node) 
{
  AvlNode *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete Songs from Playlist (Deletion in AVL tree)
AvlNode* deleteAvlNode(AvlNode *r, char* song) {
  // base case
    if (r == NULL)
    {
      printf("Song not present in the Playlist Please check\n");
        return r;
    }
    // song to be deleted find its lexicographic postion
    // If song comes first in lexicographical order than r->key, then it lies in left subtree
    if (strcmp(song,r->key)<0)
        r->left = deleteAvlNode(r->left,song);
    // If r->key comes first in lexicographical order than song, then it lies in right subtree
    else if (strcmp(song,r->key))
        r->right = deleteAvlNode(r->right,song);
 
    // if song is same as root's key,
    // then This is the node to be deleted
    else {
        // node with only one child or no child
        if (r->left == NULL) {
            AvlNode* temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL) {
            AvlNode* temp = r->left;
            free(r);
            return temp;
        }
 
        // node with two children:
        // Get the element coming first in lexographic order in the right subtree using minAvlNode function
        AvlNode* temp = minAvlNode(r->right);
        // Copy the inorder successor's string into this node
        strcpy(r->key,temp->key); 
        // Delete the inorder successor
        r->right = deleteAvlNode(r->right, temp->key);
    }
   
  r->height = 1 + max(height(r->left),height(r->right));// Update the balance factor of each node and
   // balance the AVL Tree similarly as insertion 
  int balance = getBalance(r);
  if (balance > 1 && getBalance(r->left) >= 0) 
    return rightRotate(r);

  if (balance > 1 && getBalance(r->left) < 0) 
  {
    r->left = leftRotate(r->left);
    return rightRotate(r);
  }

  if (balance < -1 && getBalance(r->right) <= 0)
    return leftRotate(r);

  if (balance < -1 && getBalance(r->right) > 0) 
  {
    r->right = rightRotate(r->right);
    return leftRotate(r);
  }

  return r;
}

/*****Playlist using AVL tree created using above functions successfully*****/
//Creating Stacks for recently played
//Defining Stack
struct stack
{
  int top,size;
  char a[100][15];
};

//Intiating global stack variable S for recently played
struct stack S;

//Push function stores the recently played song in stack
void push(char* Avl)
{
  if(S.top!=S.size-1)
  {
    S.top++;
    strcpy(S.a[S.top],Avl);
  }
}

//Pop function returns char array of song popped
char* pop()
{
  if(S.top!=-1)
  {
    char* temp = S.a[S.top];
    S.top=S.top-1;
    return temp;
  }
  else return NULL; 
}

//Creating Temporary Queue to update recently played
struct tempq
{
  int f;
  int r;
  int size;
  char a[100][15];
};
//Initating global Temporary Queue variable tempQ
struct tempq tempQ;

//Enqueue function for tempQ
void entempq(char* Avl)
{
  if((tempQ.r+1) % tempQ.size!= tempQ.f)
  {
    if(tempQ.f==-1){tempQ.f=0,tempQ.r=0;}
    else
    {
      tempQ.r=(tempQ.r+1) % tempQ.size;
    }

    strcpy(tempQ.a[tempQ.r],Avl);
  }
  else {printf("Playlist is Full\n");}
}

//Dequeue function of tempQ returns char array of song dequeued 
char* detempq()
{
  if(tempQ.f>-1)
  {
    char* temp;
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

//Inorder Traversal Function which moves inordered and updates stack and playlist after playing song
void AvlInorder(AvlNode* avl)
{
  while(avl->left!=NULL)
  {avl=avl->left;}
  printf("Playing %s\n",avl->key);
  char temp[15];
  strcpy(temp,avl->key);
  push(temp);

  Playlist = deleteAvlNode(Playlist,avl->key);
}

/**********MAIN FUNCTION**********/

int main() 
{
  //Creating file pointer
  FILE* fp;
  fp = fopen("preorder.txt","r"); //Reading file named preorder.txt

  if(fp==NULL) //Error message if file cannot be opened
  {
    printf("Sorry the file cannot be opened\n");
    return 0;
  }

  //Allocating memory for 100 char arrays each of 15 characters 
   char **a = (char**) calloc(100, sizeof(char*));

   for ( int k = 0; k <10; k++ )
  {
    a[k] = (char*) calloc(15, sizeof(char));
  }

  int i=0,j=0;
  //Reading char and storing in 2d array to insert in BST
  while(1)
  {
    char temp = fgetc(fp);
    
    if(temp!=':' && temp!=-1 && temp!='\0')
    {
      a[i][j] = temp;
      j++;   
    }

    else if(temp==':'){
     j=0;
     i++;}

    if(feof(fp)){break;}
  }
  fclose(fp);

 int Num_of_Songs = i+1;
 
 //Songs from the file inserted into Binary search tree 
 for(int k=0;k<Num_of_Songs;k++)
 {
   root = insert(root,a[k]);
 }

 printf("Song Library Created from the given file!\n");

printf("Songs in the Library are:\n");
preorder(root);

//Deleting songs not liked by user from library
printf("\nEnter songs to delete from Library :(enter -1 to stop deleting)\n");
char t[15];
while(1)
{
  scanf("%s",t);
  if(t[0]=='-' && t[1]=='1'){break;}
  if(search(root,t)!=NULL)
  {root = deleteNode(root,t);} 
}

printf("\nSongs in the Library after deleting:\n");
preorder(root);
/********Library Finalised**********/
printf("\nEnter Songs from the library to create Playlist(Enter -1 to end playlist)\n");
//Creating playlist by taking library songs from user
char pl[15];
while(1)
{
  scanf("%s",pl);
  if(pl[0]=='-' && pl[1]=='1'){break;}
else{
     BstNode* temp = search(root,pl);
     if(temp!=NULL)
     {Playlist = insertNode(Playlist,temp->key);}
    } 
}

printf("\nPlaylist Created!\n");
printf("Songs in Playlist are:\n");
Avlpreorder(Playlist);

//Deleting songs not liked by user from playlist
printf("\nEnter songs to delete from Playlist :(enter -1 to stop deleting)\n");
char v[15];
while(1)
{
  scanf("%s",v);
  if(v[0]!='-' || v[1]!=1)
  {Playlist = deleteAvlNode(Playlist,v);}
 if(v[0]=='-' && v[1]=='1'){break;}
}
printf("\nFinal Playlist Created!\n");
printf("\nSongs in the Final Playlist (after deleting):\n");
Avlpreorder(Playlist);

/********Playlist Finalised**********/

//Inital values for Recently played songs Stack
  S.top=-1;
  S.size=100;
// Intial Values Temporary Queue 
  tempQ.f=-1;
  tempQ.r=-1;
  tempQ.size=100;

//Creating Menu for Next song ; Previous songs ; End
printf("Play next song, previous songs or end? n/p:k/e\n");
while(1)
{
  char menu[3];
  scanf("%s",menu);
  if(menu[0]=='e'){break;}
  else if(menu[0]=='n')
  {
    AvlInorder(Playlist);
  }

  else if(menu[0]=='p' && menu[1]==':')
   {
     int k = (int)menu[2]-48;
     char* temp1;
     for(int i=k;i>0;i--)
     {
       if(S.top==-1)
      {printf("There aren't %d previous songs\n",k); break;}

      else
      {
        temp1=pop();
        if(temp1!=NULL)
        printf("Playing %s\n",temp1);
        else
        printf("Playlist Ended\n");
        entempq(temp1); //Enqueueing the song played from recently played song stack into temporary queue
      }
     }
     while(tempQ.f!=-1 && tempQ.r!=-1)
      {
        push(detempq()); // Updating the recently played song stack by pushing the dequeued temporary queue
      }
   }

else{printf("Command Not found\n");}
}

printf("\nBYE!\n");

 return EXIT_SUCCESS;
}