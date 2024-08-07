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

int dp[3001][3001];
int sum[3001][3001];

int solve(vector<int> &v,int i,int j)
{
    if(i==j)
    return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int mincost = inf;

    for(int k=i;k<j;k++)
    {
        mincost =  min(mincost, sum[i][j]+solve(v,i,k)+solve(v,k+1,j));
    }

      return dp[i][j] = mincost;

}


void presolve(vector<int> &v,int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=v[j]+((i==j)?0:sum[i][j-1]);
        }
    }
}

int32_t main()
{
	fast;
	int n;
    cin>>n;
    vector<int>v(n+1);

    memset(dp,-1,sizeof dp);

    for(int i=1;i<=n;i++)
        cin>>v[i];

    presolve(v,n);

    cout<<solve(v,1,n);


	return 0;
}



