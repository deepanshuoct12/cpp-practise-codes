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
int dp[10000007];
int solve(vector<int>&coins,int target)
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;

    for(int amt=1;amt<=target;amt++)
    {
        for(auto coin:coins)
        {
            if(coin<=amt){
            int remt=(amt-coin)%mod;
            dp[amt]=(dp[amt] + dp[remt])%mod;
            }
        }
    }
    return dp[target]%mod;
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
 //   sort(coins.begin(),coins.end());
    cout<<solve(coins,target);
    return 0;
}
