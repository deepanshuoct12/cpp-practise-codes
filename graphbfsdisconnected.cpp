#include<bits/stdc++.h>
using namespace std;
void helper(int n,vector<int>graph[],int idx,vector<int>&ans,vector<int>&vis)
{
    queue<int>q;
    q.push(idx);
    vis[idx]=1;
  //  ans.push_back(idx);
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(auto nbr:graph[curr])
        {
            if(!vis[nbr])
            {  vis[nbr]=1;
                q.push(nbr);
            }
        }
    }
 
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{// Write your code here
    vector<int>ans;
    vector<int>vis(vertex);
    vector<int>graph[vertex];
    for(auto x:edges){
        graph[x.first].push_back(x.second);
        graph[x.second].push_back(x.first);
    }
    for(int i=0;i<vertex;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
        
   for(int i=0;i<vertex;i++)
   {
       if(!vis[i])
           helper(vertex,graph,i,ans,vis);
   }
    return ans;
}