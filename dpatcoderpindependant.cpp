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
#define mod 1000000007
#define inf 1LL<<60

vector<int> tree[100001];
int dp[100001][2];

int solve(int u,bool constraint ,int pr)
{
    if(dp[u][constraint]!=-1)
        return dp[u][constraint];

    int ans = 0;
    int w1 = 1;
    for(int child : tree[u])
    {
        if(child!=pr)
       w1 = (w1*solve(child,0,u))%mod;
    }
   ans=(ans+w1)%mod;

    if(!constraint)
    {
        int w2 = 1;
          for(int child : tree[u])
         {
                if(child!=pr)
                 w2 = (w2*solve(child,1,u))%mod;
         }
      ans=(ans + w2)%mod;
    }

    return dp[u][constraint] = ans;
}

int32_t main()
{
	fast;
	int n;
	cin>>n;

	memset(dp,-1,sizeof dp);

	for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    cout<<solve(1,0,-1);

	return 0;
}

