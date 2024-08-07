#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define int long long int
#define mod 1000000007
#define inf 1LL<<60
int dijkstra(vector<int>g[],vector<int>v,int n)
{
    vector<bool>visited(n);
    vector<int>cost(n+2,INT_MAX);
    cost[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push({0,0});
    while(!q.empty())
    {
        pair<int,int> curr=q.top();
        q.pop();
        int node=curr.second;
        int parentcost=curr.first;
        if(visited[node])
            continue;
        visited[node]=1;
        for(auto nbr:g[node])
        {
            int edgecost=v[node];
             if(!visited[nbr] && (parentcost+edgecost < cost[nbr]))
             {
                 cost[nbr]=parentcost+edgecost;

                 if(nbr<n)
                 q.push({cost[nbr],nbr});

             }

        }
    }
    return min(cost[n],cost[n+1]);
}

int32_t main()
{
	fast;
	int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>g[n];
    for(int i=0;i<n;i++)
    {
        g[i].push_back(i+2);
        if(i!=0)
        g[i].push_back(i-1);
    }
    cout<<dijkstra(g,v,n);
	return 0;
}

