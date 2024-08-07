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

int solve(vector<int>&v,int n,int k)
{
    int dp[n+2][k+2];

    for(int j=0;j<=k;j++)
        dp[1][j]=(j>v[1])?0:1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            dp[i][j]=dp[i-1][j];

            else
            dp[i][j] = (mod + dp[i-1][j] + dp[i][j-1] - ((j-v[i]-1>=0) ? dp[i-1][j-v[i]-1]:0) )%mod;
        }
    }

     return dp[n][k];
}

int32_t main()
{
	fast;
	int n,k;

	    cin>>n>>k;

	    vector<int>v(n+1);
	    for(int i=1;i<=n;i++)
            cin>>v[i];

        cout<<solve(v,n,k)<<"\n";


	return 0;
}

