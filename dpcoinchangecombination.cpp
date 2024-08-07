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
    int dp[310][6000];
    //topdown
int helper(int amount, vector<int>& coins,int n)
    {
        if(amount==0)
            return 1;

            if(n==0)
            return 0;

        if(dp[n][amount]!=-1)
            return dp[n][amount];

        if(coins[n-1]<=amount)
        dp[n][amount]=(helper(amount,coins,n-1)+helper(amount-coins[n-1],coins,n));
        else
        dp[n][amount]=helper(amount,coins,n-1);

        return dp[n][amount];
    }

    //bottom up
int change(int amount, vector<int>& coins) {

        //   int n=coins.size();
        // int m=amount;
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         if(i==0 && j==0)
        //             dp[i][j]=1;
        //         if(i==0)
        //             dp[i][j]=0;
        //          else if(j==0)
        //             dp[i][j]=1;
        //       else if(coins[i-1]<=j)
        //       dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
        //      else
        //       dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n][m];

        //1d dp
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(coins[i]<=j)
                dp[j]=(dp[j]+dp[j-coins[i]])%mod;
            }
        }

        // for(auto x:dp)
        // cout<<x<<" ";

        return dp[amount]%mod;

    }

int32_t main()
{
      init_code();
    int n;
    cin>>n;
     int target;
    cin>>target;
  
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    cin>>coins[i];

   

    memset(dp,-1,sizeof(dp));

   // cout<<helper(target,coins,n);

     cout<<change(target,coins);

}
