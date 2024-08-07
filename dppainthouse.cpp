#include<bits/stdc++.h> // top down doubt 
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
int dp[1001][3];
int solve(int i,int n,vector<vector<int> > &v,int prev)
{

   if(i==n)
   	return 0;

   // if(dp[i][0]!=-1)
   // 	return dp[i][0];

   // if(dp[i][1]!=-1)
   // 	return dp[i][1];

   // if(dp[i][2]!=-1)
   // 	return dp[i][2];

    if(prev!=-1 && dp[i][prev]!=-1)
   	return dp[i][prev];

   if(prev==0)
   {
   	dp[i][1]=v[i][1]+solve(i+1,n,v,1);
   	dp[i][2]=v[i][2]+solve(i+1,n,v,2);

   	return min(dp[i][1],dp[i][2]);
   }
   else if(prev==1)
   {
   	dp[i][0]=v[i][0]+solve(i+1,n,v,0);
   	dp[i][2]=v[i][2]+solve(i+1,n,v,2);

   	return min(dp[i][0],dp[i][2]);
   }
   else          
   {
   	dp[i][0]=v[i][0]+solve(i+1,n,v,0);
   	dp[i][1]=v[i][1]+solve(i+1,n,v,1);

   	return min(dp[i][0],dp[i][1]);
   }
   // if(prev!=0)
  // dp[i][0]=v[i][0]+solve(i+1,n,v,0);
  //  if(prev!=1)
  //  dp[i][1]=v[i][1]+solve(i+1,n,v,1);
  // if(prev!=2)
  // 	dp[i][2]=v[i][2]+solve(i+1,n,v,2);
  // return min(min(dp[i][0],dp[i][1]),dp[i][2]);
}

//bottom up
int solve2(vector<vector<int> > &v)
{
    int n=v.size();
    int dp[n][3];
    dp[0][0]=v[0][0];
    dp[0][1]=v[0][1];
    dp[0][2]=v[0][2];

    for(int i=1;i<n;i++)
    {
    	dp[i][0]=v[i][0]+min(dp[i-1][1],dp[i-1][2]);
    	dp[i][1]=v[i][1]+min(dp[i-1][0],dp[i-1][2]);
    	dp[i][2]=v[i][2]+min(dp[i-1][0],dp[i-1][1]);
    }

    return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

}
int32_t main()
{
   fast;
   init_code();
   int n;
   memset(dp,-1,sizeof(dp));
    cin>>n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
    	v.pb({x,y,z});
    }
   // cout<<solve(0,n,v,-1)<<"\n";
    cout<<solve2(v);
	return 0;
}