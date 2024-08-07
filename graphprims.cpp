#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
class graph{
public:
    int v;
    list<pair<int,int> >*adj;
    graph(int v)
    {
        this->v=v;
        adj = new list<pair<int,int> >[v];
    }

    void addedge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    int findminvertex(int *weight, bool *visited,int v)
    {

        int minvertex = -1;
         int minval=INT_MAX;
        for(int i=0;i<v;i++)
        {
            if(!visited[i] && (minvertex==-1 ||  weight[i]<minval))
            {
                minvertex=i;
                minval=weight[i];
            }
        }

        return minvertex;
    }


    void prims()
    {
        bool *visited =new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];

        for(int i=0;i<v;i++)
        {

            weight[i]=inf;
            visited[i]=false;
        }
        parent[0]=-1;
        weight[0]=0;

        for(int i=0;i<v;i++)
        {
          int minvertex = findminvertex(weight,visited,v);

          visited[minvertex]=true;
          for(auto neighbour : adj[minvertex])
          {
              if(!visited[neighbour.first])
              {  if(weight[neighbour.first]>neighbour.second)
                  {
                  parent[neighbour.first]=minvertex;
                  weight[neighbour.first]=neighbour.second;
                  }

              }
           }
        }

        for(int i=1;i<v;i++)
        {
            cout<<i<<"-->"<<parent[i]<<"with weight"<<weight[i]<<endl;
        }

    }

};
int main()
{
  int n,e;
  cin>>n;
  cin>>e;
     graph g(n);
  for(int i=0;i<e;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      g.addedge(u,v,w);

  }
  g.prims();


}
