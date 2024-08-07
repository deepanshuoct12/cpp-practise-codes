#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mod 1000000007
#define inf 1LL<<60
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
vector<int> dijkstra(vector<vector<pair<int,int> > > &g, int src){
        int n = g.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
        q.push({0,src});
        while(!q.empty())
        {
            auto x = q.top();
            q.pop();
            int nodeweight = x.first;
            int node = x.second;
            if(dist[node]!=INT_MAX)
                continue;
            dist[node] = nodeweight;
            for(auto nbr : g[node])
            {
                int edgeweight = nbr.second;
                int v=nbr.first;
                if(edgeweight+nodeweight < dist[v])
                  {
                      q.push({edgeweight+nodeweight,v});
                  }
            }
        }
        return dist;
}


int32_t main(){
    int n,m;
     init_code();
     cin>>n>>m;
   vector<vector<pair<int,int>>>g(n+1);
    for(int i=0;i<m;i++)
    {
        int l,r,w;
        cin>>l>>r>>w;
        for(int x=l;x<r;x++)
        {
        	for(int y=x+1;y<=r;y++)
        		g[x].pb({y,w});
        }

    }

     vector<int>ans=dijkstra(g,0);
     for(auto x:ans)
        cout<<x<<" ";
return 0;
}
