#include<bits/stdc++.h>
using namespace std;

vector<int> bellman(int src,int n,vector<vector<int> >edge)
{
    vector<int>dis(n+1,INT_MAX);
    dis[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto x:edge)
        {
            int from=x[0],to=x[1],weight=x[2];
            if(dis[from]!=INT_MAX && dis[from]+weight<dis[to])
                dis[to]=dis[from]+weight;
        }
    }
        for(auto x:edge)
        {
            int from=x[0],to=x[1],weight=x[2];
            if(dis[from]!=INT_MAX && dis[to]>weight+dis[from])  ///we get a new shprtest path for to
             {
                cout<<"negative cycle";
                exit(0);
             }

        }
    return dis;
}
int main(){

    int n,e;
    cin>>n>>e;
    vector<vector<int> >edge;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    vector<int> dis=bellman(1,n,edge);

  for(int i=1;i<=n;i++)
  cout<<"dis from src to"<<" "<<i<<"-->"<<dis[i]<<"\n";

return 0;
}
