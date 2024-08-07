#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
    int src,dest;

};

class Set{

public:
    int rank;
    int parent;
};

int findset(Set *set,int i)
{
    if(set[i].parent!=i)
    {
       set[i].parent= findset(set,set[i].parent);
    }
    return set[i].parent;

}

void Union(Set *set,int v1,int v2)
{
    int v1_root = findset(set,v1);
    int v2_root = findset(set,v2);

    if(set[v1_root].rank<set[v2_root].rank)
    {
        set[v1_root].parent=v2_root;
    }
    else if(set[v1_root].rank>set[v2_root].rank)
    {
        set[v2_root].parent=v1_root;
    }
    else
    {
        set[v2_root].parent=v1_root;
        set[v1_root].rank++;
    }
}

bool iscycle(edge *input,int n,int e)
{


  Set *set = new Set[n];
  for(int i=0;i<n;i++)
  {
      set[i].parent =i;
      set[i].rank = 0;
  }
  int counter=0,i=0;

  while( i<e)
  {
      edge currentedge = input[i];
      int parent1= findset(set,currentedge.src);
      int parent2= findset(set,currentedge.dest);

      if(parent1 == parent2)
      {
          return true;

      }

          Union(set,parent1,parent2);
          i++;

  }
  /*cout<<output[0].src<<"--"<<output[0].dest<<"\n";
  cout<<output[1].src<<"--"<<output[1].dest<<"\n";
  cout<<output[2].src<<"--"<<output[2].dest<<"\n";
  cout<<output[3].src<<"--"<<output[3].dest<<"\n";
  cout<<output[4].src<<"--"<<output[4].dest<<"\n";
  cout<<output[5].src<<"--"<<output[5].dest<<"\n";*/
 // cout<<n<<"\n";
  return false;
}


int main()
{
    int n,e;
    cin>>n>>e;
    edge *input = new edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        input[i].src=s;
        input[i].dest=d;

    }
    cout<<iscycle(input,n,e);
    return 0;

}
