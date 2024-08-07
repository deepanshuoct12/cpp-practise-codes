#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define N 10005
vector<int> graph[N],revgraph[N];
vector<int>order;
int comp[N];
void dfs(int src,vector<bool> &visited)
{
    visited[src]=true;
    for(auto x:graph[src])
    {
      if(!visited[x])
        dfs(x,visited);
    }
    order.push_back(src);
}
void dfs_reversegraph(int src,vector<bool> &visited,int col)
{
    comp[src]=col;
    visited[src]=true;

    for(auto x:revgraph[src])
    {
      if(!visited[x])
        dfs_reversegraph(x,visited,col);
    }

}
int32_t main(){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    revgraph[y].push_back(x);
}
 vector<bool> visited(n+1,false);
 for(int i=1;i<=n;i++)
 {
     if(!visited[i])
      dfs(i,visited);
 }
 for(int i=0;i<visited.size();i++)
  visited[i]=false;
int col=1;



 for(int i=n-1;i>=0;i--)
 {
     if(!visited[order[i]])
    {
        dfs_reversegraph(order[i],visited,col);
         col++;
    }
 }
 for(int i=1;i<=n;i++)
 cout<<comp[i]<<" ";
 cout<<"\n"<<"componenets="<<col-1;
return 0;
}


