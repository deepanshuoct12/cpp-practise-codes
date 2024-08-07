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


int dp[22][1<<22];

int solve(vector<vector<int> > &compat,int i,int womansubset,int N)
{
    if(i== N+1)
    {
        if(womansubset==0)
            return 1;
        return 0;
    }

    if(dp[i][womansubset]!=-1)
        return dp[i][womansubset];

    int ans =0;
    for(int woman = 0;woman<N;woman++)
    {
        bool available = (((1<<woman)&(womansubset))==0)?0 : 1;

        if(available && compat[i][woman+1])
        {
        ans = (ans + solve(compat,i+1,womansubset^(1<<woman),N))%mod;
        }
    }

    return dp[i][womansubset] = ans;
}

int32_t main()
{
	fast;
	int n;
    cin>>n;
    vector< vector<int > >compat(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          cin>>compat[i][j];

    memset(dp,-1,sizeof dp);

    cout<<solve(compat,1, ((1<<(n))-1) ,n)<<"\n";

	return 0;
}

