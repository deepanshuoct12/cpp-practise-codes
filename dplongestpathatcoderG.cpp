#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int

vector<int> graph[10000];
int dp[1000];

int solve(int src)
{
    if(dp[src]!=-1)
        return dp[src];

    bool leaf =1;
    int bestchild =0;

    for(int child : graph[src])
    {
        leaf = 0;

        bestchild = max(bestchild,solve(child));

    }

    return dp[src] = leaf?0:1+bestchild;

}


int32_t main()
{
	fast;
	int n,m;
	    cin>>n>>m;
	    memset(dp,-1,sizeof dp);
	    for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
        }
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            ans = max(ans,solve(i));
        }
         cout<<ans<<"\n";

	return 0;
}

