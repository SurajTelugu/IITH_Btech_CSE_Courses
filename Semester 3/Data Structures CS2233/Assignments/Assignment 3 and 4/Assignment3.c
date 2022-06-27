#include <stdio.h>
#include <stdlib.h>


#define t 10 // Given t = 10 in the problem 

// Global values for finding time
unsigned exetime = 0;
unsigned createtime = 0;
unsigned searchtime = 0;
unsigned deletetime = 0;

// Given Data
int keys[60] = {17,13,2,27,48,54,39,57,60,3,23,
  46,16,18,49,45,33,36,55,19,47,35,7,22,4,50,9,56,
  37,12,11,21,31,38,29,44,8,26,25,40,6,58,51,1,15,30,
  52,10,28,59,53,34,43,42,24,14,32,41,5,20};

// Define struct for coordinate pair in secondary memory 
struct coordn
{
  int x; int y;
};

typedef struct coordn coordn;

// Define struct for memory cell 
struct MemoryCell
{
  int key;
  coordn left; 
  coordn right;
};

typedef struct MemoryCell memorycell;

memorycell p[2][2*t]; //defining primary memory
memorycell b[5][2*t]; // defining secondary memory

coordn nulltype = {-1,-1}; // coordinate (-1,-1) is similar to null pointer

//Function to empty the primary memory 
void emptypm(unsigned row)
{
  for(int i=0;i<20;i++)
  {
    p[row-1][i].key = 0;
    p[row-1][i].left = nulltype;
    p[row-1][i].right = nulltype;
  }
}

//Function to use primary memory used to find execution time  
memorycell* getpm(int x,int y)
{
  exetime++; // 1 unit time to access primary cell 
  memorycell* cell = &p[x-1][y-1];
  return cell;
}

// write disk function which makes changes in secrow of secondary memory 
void writedisk(unsigned secrow,unsigned prirow)
{
  memorycell* pm;
  for(int i=0;i<20;i++)
  {
    pm = getpm(prirow,i+1);
     b[secrow-1][i].key = pm->key;
     b[secrow-1][i].left = pm->left;
     b[secrow-1][i].right = pm->right;  
  }

  exetime = exetime + 10; // 10 units execution time for using writedisk
}

// read disk function which reads from secrow of secondary memory into prirow of primary memory 
void readdisk(unsigned secrow,unsigned prirow)
{
  memorycell* pm;
  for(int i=0;i<20;i++)
  {
    pm = getpm(prirow,i+1);
    *pm = b[secrow-1][i]; 
  }

  exetime = exetime+10; // 10 units execution time for using readdisk
}

// psuedo search function which gives coordinates of key in secondary memory 
coordn getcoordn(int key)
{
  coordn idx = nulltype;
  int i=0;
  for(i=0;i<60;i++)
  {
    if(key==keys[i]){break;}
  }
  if(i==60){return nulltype;}
  else
  {
  if((i+1) % 20!=0)
  {idx.x = (i+1)/20 + 1; idx.y = (i+1) % 20;}
  else 
  {idx.x = (i+1)/20; idx.y = 20;}

  return idx;
  }
}

/**************************Virtual Binary Search tree********************************************/
//Creating Node for Binary search tree
struct BstNode
{
    int key;
    struct BstNode *left, *right;
};
typedef struct BstNode BstNode;

//Initializing global Binary search tree pointer 
BstNode* bstroot=NULL;

//Function to create New Node for BST 
BstNode* newNode(int key)
{
  bstroot = (BstNode*) malloc(sizeof(BstNode));
  bstroot->key = key;
  bstroot->left = bstroot->right = NULL;
  return bstroot;
}

//Insert function for bst
BstNode* insert(BstNode* r,int key)
{
    if(r==NULL)
        r = newNode(key); //Creating newnode 
  
 //Searching place to insert node
 else if(key > r->key) 
    {    
      r->right = insert(r->right,key);
    }
 else if(key < r->key) 
    {
      r->left = insert(r->left,key);
    }
  else if(r->key == key) 
    {printf("Error Element already exist\n");}
 

  return r;
}

//Search function for bst
BstNode* search(BstNode* r,int key)
{
    if(r==NULL)
    {return NULL;}
     if(r->key == key) return r;
     if(key < r->key) 
    {return search(r->left,key);}
    else 
    {return search(r->right,key);}
    
}

//Function which gives left child of given node
int getleftchild(BstNode* r,int key)
{
  r = search(r,key);
  if(r==NULL){return -1;}
  else
  {
    if(r->left!=NULL) return r->left->key;
    else return -1;
  }
}

//Function which gives rigjht child of given node
int getrightchild(BstNode* r,int key)
{
  
  r = search(r,key);
  if(r==NULL){return -1;}
  else
  {
    if(r->right!=NULL) return r->right->key;
    else return -1;
  }
}

//Function which gives minimum element of given BST
BstNode* find_minimum(BstNode* node)
{
    BstNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

//Function which gives parent node of given element in BST
BstNode* findparent(BstNode* r, int key)
{
   if(r->left == NULL && r->right == NULL)
    return NULL;

   if( (r->left != NULL && r->left->key == key)
        || (r->right != NULL && r->right->key == key))
    return r;

   if(r->key > key)
    return findparent(r->left,key);

   else
    return findparent(r->right,key);
}

//Delete function of BST
BstNode* deleteNode(BstNode* r,int key)
{
    // base case
    if (r == NULL)
        return r;

    if (key < r->key)
        r->left = deleteNode(r->left,key);

    else if (key > r->key)
        r->right = deleteNode(r->right,key);
 
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
        BstNode* temp = find_minimum(r->right);
        // Copy the temp's content to this node
        r->key = temp->key;
        // Delete the inorder successor
        r->right = deleteNode(r->right, temp->key);
    }
    return r;
}

/*********************Binary search tree in secondary memory************************************/

//Inserts the left and right indices of a key as per BST and stores in secondary memory
void insertbst(int key)
{
   coordn idx = getcoordn(key); // getting coordinates of key 

  readdisk(idx.x,1);
  memorycell* pm = getpm(1,idx.y); // getting memory cell of key 

  int left = getleftchild(bstroot,key); // left child of key is obtained 
  int right = getrightchild(bstroot,key); // right child of key is obtained 

  if(left!=-1) pm->left = getcoordn(left); // updating left coordinate of memorycell
  else pm->left = nulltype;

  if(right!=-1) pm->right = getcoordn(right); // updating right coordinate of memory cell
  else pm->right = nulltype;
 
  writedisk(idx.x,1); // updating that row of disk with the updated memory cell
  emptypm(1);
}

// Searches given element by their indices 
coordn searchbst(coordn idx,const int key)
{
  if(idx.x!=-1 && idx.y!=-1)
  {
   readdisk(idx.x,1);
   memorycell* pm = getpm(1,idx.y);

  if(key == pm->key) 
  {
    return idx;
  }
 else 
 {
   if((pm->left.x!=-1 && pm->left.y!=-1)  || 
   (pm->right.x!=-1 && pm->right.y!=-1))
   {
     if(key < pm->key) 
     {
       idx = pm->left;
       idx = searchbst(idx,key);
     }

     else if(key > pm->key) 
     {
       idx = pm->right;
       idx = searchbst(idx,key);
     }
   }
 }
 }
  
  return idx; emptypm(1);
}

// Deletes a given element from BST and updates indices accordingly 
void deletebst(int key)
{
  if(key>0 && key<=60)
  {
    int parent,leftchild,rightchild;
    parent    = findparent(bstroot,key)->key; // parent of given key 
    leftchild = getleftchild(bstroot,key);    // left child of given key 
    rightchild = getrightchild(bstroot,key);  // right child of given key 
    BstNode* key_bst = search(bstroot,key);   // Node of key in BST
    BstNode* inordersuccessor = find_minimum(key_bst); // Inorder successor of BST
    int inorderparent = findparent(bstroot,inordersuccessor->key)->key; // Parent of inorder successor 

    bstroot = deleteNode(bstroot,key);

    if(leftchild==-1 && rightchild==-1) //No child
    { 
      insertbst(parent);
      coordn idx = getcoordn(key);
      readdisk(idx.x,1);
      memorycell* pm = getpm(1,idx.y);
      pm->key = 0; pm->left = nulltype; pm->right = nulltype;
      writedisk(idx.x,1); emptypm(1);
    }
  else
  {
    if(leftchild==-1 || rightchild==-1) //One child
    {
       insertbst(parent);
       if(leftchild!=-1){insertbst(leftchild);}
       else insertbst(rightchild);

      coordn idx = getcoordn(key);
      readdisk(idx.x,1);
      memorycell* pm = getpm(1,idx.y);
      pm->key = 0; pm->left = nulltype; pm->right = nulltype;
      writedisk(idx.x,1); emptypm(1);
    }

    else if(leftchild!=-1 && rightchild!=-1) // Two children 
    {
      insertbst(leftchild); insertbst(rightchild); insertbst(parent);
      insertbst(inordersuccessor->key); insertbst(inorderparent);

      coordn idx = getcoordn(key);
      readdisk(idx.x,1);
      memorycell* pm = getpm(1,idx.y);
      pm->key = 0; pm->left = nulltype; pm->right = nulltype;
      writedisk(idx.x,1);  emptypm(1);
    }
  }
  }

  else 
  {
    printf("%d not present in memory\n",key);
  }
}


int main() 
{
  printf("Memory hirearchy and execution using Binary Search tree\n\n");
  
  emptypm(1); emptypm(2);

  memorycell* pm;
  
  // Initiating memory cells of secondary memory with keys and null indices 
  for(int j=1;j<=3;j++)
  {
   for(int i=0;i<20;i++)
   {
    pm = getpm(1,i+1);
    pm->key = keys[i+20*(j-1)];
   }
 
   writedisk(j,1);
  }

  emptypm(1);
  // Inserting into Binary search trew
  for(int i=0;i<60;i++)
  {
    bstroot = insert(bstroot,keys[i]);
  }
  // Updating Indices of every element and filling them in secondary memory with insertbst
  for(int i=0;i<60;i++)
  {
    insertbst(keys[i]);
  }
  createtime = exetime; // time taken to create is execution time until now 
  printf("Time taken for creation of data structure (BST): %u\n\n",createtime);

  // Elements given for search 
  int searchkey[9] = {49,27,22,38,11,55,7,35,59};
  for(int i=0;i<9;i++)
  {
  coordn idx = {1,1};
  searchtime = exetime;
  idx = searchbst(idx,searchkey[i]);
  searchtime = exetime - searchtime; // Time taken for search is the timeperiod unti search function runned
  if(idx.x!=-1 && idx.y!=-1)
  {
    printf("%d found in secondary memory at (%d,%d)\n",searchkey[i],idx.x,idx.y);
    printf("Time taken to search %d: %u\n",searchkey[i],searchtime);
  }

  else 
  {
    printf("Element not found in memory\n");
  }
  }
  
   printf("\n");
  
  int deletekey[9] = {13,19,24,37,43,53,18,38,58};
  for(int i=0;i<9;i++)
  {
    deletetime = exetime;
    deletebst(deletekey[i]);
    deletetime = exetime - deletetime;// Time taken for search is the timeperiod until delete function runned
    printf("%d deleted from secondary memory at\n",deletekey[i]);
    printf("Time taken to delete %d: %u\n",deletekey[i],deletetime);
  }

  return EXIT_SUCCESS;
}