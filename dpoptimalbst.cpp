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
#define inf 1LL<<60
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int solve(int n,vector<int>&keys,vector<int>&freq)
{
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	vector<int>pre(n);
	pre[0]=freq[0];
	 for(int i=1;i<n;i++)
         pre[i]+=freq[i]+pre[i-1];

	for(int len=0;len<n;len++)
	{
      for(int start=0;start<n-len;start++)
      {
      	int end=start+len;
      	if(len==0)
      		dp[start][end]=freq[start];
      	else if(len==1)
      	{
      		int f1=freq[start];
      		int f2=freq[end];

      		dp[start][end]=min(f1+2*f2,f2+2*f1);
      	}
      	else{
          int mn=INT_MAX;
          int fsum=0;
          // for(int i=start;i<=end;i++)
          // 	fsum+=freq[i];
           fsum=pre[end]-(start==0?0:pre[start-1]);
          for(int k=start;k<=end;k++)
          {
          	int left=k==start?0:dp[start][k-1];
          	int right=k==end?0:dp[k+1][end];
          	if(left+right+fsum<mn)
          	{
          		mn=left+right+fsum;
          	}
          }

          dp[start][end]=mn;
      	}
      }
	}
	
	return dp[0][n-1];
}
int32_t main()
{
   fast;
   init_code();
   int n;
    cin>>n;
    vector<int>v(n),freq(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
     for(int i=0;i<n;i++)
    	cin>>freq[i];
      cout<<solve(n,v,freq);
	return 0;
}