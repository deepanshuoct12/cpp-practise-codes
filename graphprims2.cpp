#include<bits/stdc++.h>
using namespace std;
vector<int> prims(vector<vector<pair<int,int> > > &g, int src){
        int n = g.size();
        vector<int> dist(n, INT_MAX);
     //   vector<bool> visited(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
        q.push({0,src});

        while(!q.empty())
        {
            auto x = q.top();
            q.pop();
            int nodeweight = x.first;
            int node = x.second;

            //if(visited[node])
            //    continue;

             if(dist[node]!=INT_MAX)
                continue;

           // visited[node]=true;

            dist[node] = nodeweight;
            //cout<<node<<"->";
            for(auto nbr : g[node])
            {
                int edgeweight = nbr.second;
                int v=nbr.first;

                if(edgeweight < dist[v])
                  {
                      q.push({dist[v],v});
                  }
            }

        }

        return dist;
}

int main(){
    int n,e;
     cin>>n>>e;
   vector<vector<pair<int,int>>>g(n);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

     vector<int>ans =prims(g,0);
      int res=0;
     for(auto x:ans)
      res+=x;

      cout<<res;
return 0;
}

/////////////////return MST///////////
/*
#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>,int>> helper(vector<vector<pair<int,int>> > &graph, int src, int n)
{
   priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int>> > > q;
    q.push({0,{src,-1}});
    
    vector<int>dist(n+1,INT_MAX);
       vector<int>parent(n+1);
    while(!q.empty()){
      pair<int,pair<int,int> > v=q.top();
        q.pop();
        int nodeweight=v.first;
        int node = v.second.first;
        int p=v.second.second;
        
        if(dist[node]!=INT_MAX){
            continue;
        }
        
        dist[node]=nodeweight;
        parent[node]=p;
        
        for(auto nbr:graph[node]) {
            int edgeweight = nbr.second;
            int v=nbr.first;
            
            if(dist[v]>edgeweight){
                q.push({edgeweight,{v,node}});
            }
        }
    }
    vector<pair<pair<int,int>,int > >mst;
    for(int i=2;i<=n;i++){
        int p=parent[i];
        mst.push_back({{p,i},dist[i]});
    }
    return mst;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0;i<m;i++) {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        
        graph[u].push_back({v,w});
    }
// vector<pair<pair<int, int>, int>> mst;
   // return mst;
    return helper(graph,1,n);
    
    
    
    // Write your code here.
}

*/