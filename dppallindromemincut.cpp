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
//O(n*n*n)
int solve(string str)
{
	int n=str.length();
	int dp[n][n];
	memset(dp,0,sizeof(dp));

	for(int len=0;len<n;len++)
	{
		for(int start=0;start<n-len;start++)
		{
			int end=start+len;
            if(len==0)
            	dp[start][end]=1;
            else if(len==1)
            {
            	if(str[start]==str[end])
            		dp[start][end]=1;
            }
            else{
               if(str[start]==str[end] && dp[start+1][end-1])
                  dp[start][end]=1;
            }
		}
	}

	int storage[n][n];
	for(int len=0;len<n;len++)
	{
		for(int start=0;start<n-len;start++)
		{
			int end=start+len;
            if(len==0)
            	storage[start][end]=0;
            else if(len==1)
            {
            	if(str[start]==str[end])
            		storage[start][end]=0;
            	else 
            	   storage[start][end]=1;
            }
            else{
               if(dp[start][end])
                 storage[start][end]=0;
             else{
             	int mn=INT_MAX;
             	for(int k=start;k<end;k++)
             	{
             		int left=storage[start][k];
             		int right=storage[k+1][end];

             		if(left+right+1<mn)
             		{
             			mn=left+right+1;
             		}
             	}
                storage[start][end]=mn;
             }
            }
		}
	}


	return storage[0][n-1];
}


int32_t main()
{
   fast;
   init_code();
   string str;
   cin>>str;
    cout<<solve(str);
	return 0;
}