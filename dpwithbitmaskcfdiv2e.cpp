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
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
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
double prob[20][20];
double dp[262145];

double pmove(int prevmask,int j,int n)
{
	int k=__builtin_popcount(prevmask);
	double deno=(k*(k-1))/2;
    double mprob=0;
	for(int fish=0;fish<n;fish++)
	{
		if(prevmask&(1<<fish))
		{
          mprob+=prob[fish][j];
		}
	}
	return (mprob/deno);
}
double solve(int mask,int n)
{
	int cnt=__builtin_popcount(mask);
	if(cnt==n)
		return 1;

	if(dp[mask]>-0.9)
		return dp[mask];

    double ans=0;
	for(int fish=0;fish<n;fish++)
	{
		if(!(mask&(1<<fish)))
		{   int prevmask=mask^(1<<fish);
			double prevprob=solve(prevmask,n);
            ans+=(pmove(prevmask,fish,n)*prevprob);
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
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cin>>prob[i][j];
    }
    for(int i=0;i<n;i++)
    {
    	prDouble(solve((1<<i),n));
    	cout<<" ";
    }
	return 0;
}