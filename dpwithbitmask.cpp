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
int dp[10485877];
int solve(vector<vector<int> > &cost,int i,int mask,int n)
{
	if(i>=n)
		return 0;
     
     if(dp[mask]!=-1)
     return dp[mask];

     int ans=INT_MAX;
	for(int j=0;j<n;j++)
	{
		if((mask&(1<<j))==0)
		{
           ans=min(ans,cost[i][j]+solve(cost,i+1,mask|(1<<j),n));
		}
	}
	return dp[mask]=ans;
}
int32_t main()
{
   fast;
   init_code();
   int n;
   cin>>n;
   vector<vector<int> > cost(n,vector<int>(n,0));
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   		cin>>cost[i][j];
   	}
   }
   memset(dp,-1,sizeof(dp));
   cout<<solve(cost,0,0,n);
	return 0;
}