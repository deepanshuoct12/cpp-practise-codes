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
#define pop pop_back
#define int unsigned long long int
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
int solve(vector<int> &profit, vector<int> &wt, int C) {
     
   int mxm=0;
   mxm=accumulate(profit.begin(),profit.end(),0);
   int n=profit.size();
   int dp[n+1][mxm+1];
   memset(dp,0,sizeof(dp));
   
  // cout<<mxm;
   for(int i=1;i<=mxm;i++)
     dp[0][i]=1e18;
     int ans=0;
     for(int i=1;i<=n;i++)
     {
         for(int j=0;j<=mxm;j++)
         {
             if(profit[i-1]>j)
             dp[i][j]=dp[i-1][j];
             else 
             dp[i][j]=min(dp[i-1][j],wt[i-1]+dp[i-1][j-profit[i-1]]);
             
             if(dp[i][j]<=C)
             ans=max(ans,j);
         }
     }
     return ans;
   
}
int32_t main() {
  fast;
  int n,w;
  cin>>n>>w;
  vector<int>wt(n),profit(n);
  for(int i=0;i<n;i++)
  cin>>wt[i]>>profit[i];
  //cout<<wt[0]<<" "<<profit[0]<<"\n";
  int val=solve(profit,wt,w);
  cout<<val<<"\n";
	return 0;
}