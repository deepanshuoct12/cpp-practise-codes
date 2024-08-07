#include<bits/stdc++.h>
using namespace std;

class Graph{

   map<int,vector<pair<int,int> > >adj;
  public:
  Graph()
  {

  }
  void print()
  {
      for(auto vec:adj)
    {
        cout<<vec.first<<":";
        for(auto x:vec.second)
        cout<<x.first<<",";

        cout<<"\n";
    }
  }
  void addedge(int u,int v,int w,bool bidir=true)
  {
      adj[u].push_back({v,w});
      if(bidir)
      adj[v].push_back({u,w});

  }
  bool detectcycle(int src ,map<int,bool>&visited,int parent)
  {
      visited[src]=true;
      for(auto nbr:adj[src])
      {
          if(!visited[nbr.first])
          {
              if(detectcycle(nbr.first,visited,src))
              return true;
          }
          else  if(nbr.first!=parent) {
              return true;
          }
      }
      return false;
  }

  bool dfsdetectcyle()
  {
      map<int,bool>visited;
      for(auto x:adj)
      {
          if(visited[x.first]==false)
          {
              //cout<<x.first<<" ";
              if(detectcycle(x.first,visited,x.first))
              return true;
          }
      }
      return false;
  }

};

int main()
{
    int v,e;
    cin>>v>>e;
    Graph g;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w);
    }
   // g.print();

    if(g.dfsdetectcyle())
    cout<<"true";
    else
    cout<<"false";

    return 0;
}
