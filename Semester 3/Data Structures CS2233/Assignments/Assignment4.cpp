#include <iostream>
#include <set>
#include <queue>

#define Nodes 100 // Given 100 Nodes are taken

using namespace std;

enum Coin{Heads,Tails}; // Defining a enum for heads and tails for readability

//Create graph function helps to an adjacent matrix for the graph
void CreateGraph(int** mat, int n)
{
  
  for(int i=0;i<n;i++)
  {
    mat[i][i] = 0;
    srand(time(NULL));
    for(int j=i+1;j<n;j++) 
    {
      if(rand()%2 == Heads) //if random number is even then it is heads
      {mat[i][j] = 1; mat[j][i] = 1;}

      else //if random number is odd then it is tails
      {mat[i][j] = 0; mat[j][i] = 0;}
    }
  }

  // for(int i=0;i<n;i++)
  // {mat[i][i] = 0;}

}

//Structure of Given Node is defined
struct Node
{
  int NodeID;
  int TimeStamp;
  string Event_type;
};

//Global Node VAriables are declared 
Node V[100];

//Compare used in defining priority queues
struct Compare 
{
    bool operator()(Node const& n1,Node const& n2)
    {
      if(n1.TimeStamp!=n2.TimeStamp)
      {return !(n1.TimeStamp < n2.TimeStamp);}
       else
       {return !(n1.NodeID < n2.NodeID);}
    }
};

//Infection time is given by this function i.e first head 
int InfectionTime()
{
  int j = 1;

  srand(time(NULL));
  while(j<6) 
  {
    if(rand()%2 == 0){break;}
    j++;
  }

  return j;
}

// Returns shortest distance of a given node from start node
int SD_BFS(int** adj, int start, int end)
{
  bool Visit[Nodes] = {false};
  int Dist[Nodes] = {-1};

  queue<int> bfsq;
  bfsq.push(start);

    Visit[start] = true;
    Dist[start] = 0;
  
    int vis;
    while (!bfsq.empty()) 
    {
        vis = bfsq.front();
        bfsq.pop();

        for (int i = 0; i < Nodes; i++) 
        {
            if (adj[vis][i] == 1 && (!Visit[i])) 
            {
                bfsq.push(i);
                Visit[i] = true;
                Dist[i] = Dist[vis]+1;
            }
        }
    }

    return Dist[end];
}




int main() 
{
  // Allocating memory for adjacency matrix to crate a graph
  int** adjmat = (int**) calloc(Nodes, sizeof(int*));
  for ( int i=0; i<Nodes; i++ ) 
  {adjmat[i] = (int*) calloc(Nodes, sizeof(int));}

  CreateGraph(adjmat,Nodes); // Graph Creation
  
  set <int,greater<int>> S,R,I; //defining Suceptible recovered and infected people sets 

  for(int i=1;i<=Nodes;i++) 
  {
    S.insert(i); // Inserting all nodes into suceptible
    V[i-1].Event_type = "Suceptible";
  } 
  

  Node infected;
  srand(time(NULL));
  infected.NodeID = rand()%Nodes + 1;
  infected.TimeStamp = 0;
  infected.Event_type = "Infection";
  
  priority_queue <Node,vector<Node>,Compare> Q; // Defining priority queue
  Q.push(infected);

  Node u;
    u.NodeID = infected.NodeID;
    srand(time(NULL));
    u.TimeStamp = (infected.TimeStamp + 1+ rand()%5);
    u.Event_type= "Recovery";
    Q.push(u);

  cout<<"Simulation for the population Graph is given below\n"<<endl;
  int Time = 0;
   cout<<"___________________________________________________________"<<endl;
  cout<<"Days"<<" |"<<"Suceptable people"<<" |"<<"Infected People"<<" |"<<"Recovered People"<<"|"<<endl;
  int p=0;
  while(!Q.empty())
  {
    Node e = Q.top(); 
    
    Q.pop();
  
    if(e.Event_type == "Recovery")
    {
      R.insert(e.NodeID); 
      I.erase(e.NodeID);
    }
    
    if(e.Event_type == "Infection")
    {
      I.insert(e.NodeID);
      S.erase(e.NodeID);
      
      int row = (e.NodeID-1);
    
      for(int i=0;i<Nodes;i++)
      {
        if(adjmat[row][i] == 1)
        {
          if(V[i].Event_type!="Recovery") 
          {
            V[i].NodeID = i+1;
            int j = InfectionTime();

            if(j==6) {continue;}
            
            else
          {
            if( V[i].Event_type=="Suceptible")
            {
              V[i].TimeStamp = (e.TimeStamp + j);
              V[i].Event_type = "Infection";
              Q.push(V[i]);

              srand(time(NULL));
              int k = V[i].TimeStamp+1+rand()%5;
              V[i].TimeStamp = k-1;
              V[i].Event_type = "Recovery";
              Q.push(V[i]);

            }

          }
        }
         }
      }
    }  

    if((Q.top().TimeStamp) > Time)
    {
      cout<<Time<<"    |"<<"        "<<S.size()<<"        |"<<
      "       "<<I.size()<<"        |"<<"        "<<R.size()<<"       |"<<endl;
      Time++;
    }
  }
  cout<<Time<<"    |"<<"        "<<S.size()<<"        |"<<
      "       "<<I.size()<<"        |"<<"        "<<R.size()<<"       |"<<endl;
  cout<<"______________________________________________________________"<<endl;

cout<<"\nThe shortest distance from Infected Node "<<infected.NodeID<<" with other nodes is given below"<<endl;

for(int i=0;i<Nodes;i++)
{
  int SD = SD_BFS(adjmat,infected.NodeID-1,i);
  if(SD > 0)
  { cout<<"The instant at which Node "<<i+1<<" gets infected is "<<SD<<endl;}

  else if(SD < 0)
  {cout<<"The Node "<<i+1<<" cannot be infected"<<endl;}
}

 return 0; 
} 