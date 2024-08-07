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

int dp[1000][1000];
//top down
int solve(int n,int k)
{
     if(n==0 || k==0 || k>n)
     	return 0;
     if(k==1 || k==n)
     	return 1;

      if(dp[n][k]!=-1)
      	return dp[n][k];

	int ans=k*solve(n-1,k)+solve(n-1,k-1); 
	
	return dp[n][k]=ans;
}

// bottom up
int solve2(int n,int k)
{
   memset(dp,0,sizeof(dp));
   for(int i=0;i<=n;i++)
   	dp[i][0]=0;

   for(int i=0;i<=k;i++)
   	dp[0][i]=0;

   for(int i=1;i<=n;i++)
   {
   	for(int j=1;j<=i;j++)
   	{
       if(j==i)
       	dp[i][j]=1;
       else 
       	dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
   	}
   }
   return dp[n][k];
}
int32_t main()
{
   fast;
   init_code();
 //  memset(dp,-1,sizeof(dp));
   int n,k;
   cin>>n>>k;
   cout<<solve2(n,k);
	return 0;
}