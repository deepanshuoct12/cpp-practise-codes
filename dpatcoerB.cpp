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
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mod 1000000007
#define inf 10007
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int dp[100007];
int solve(int i,int n,vector<int>&v,int k)
{
	if(i==n-1)
	{
		return 0;
	}
	if(dp[i]!=-1)
		return dp[i];
	
    int op1=INT_MAX;
    for(int j=1;j<=k;j++)
    {
         if(i+j<n)
          op1=min(op1,abs(v[i+j]-v[i])+solve(i+j,n,v,k));
        
    }
    dp[i]=op1;
     //cout<<op1;//<<" "<<op2<<"\n";
	return dp[i];

}
int32_t main()
{
   fast;
   init_code();
   memset(dp,-1,sizeof(dp));
   int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    cout<<solve(0,n,v,k);
	return 0;
}