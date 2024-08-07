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
#define mod 1000000007
#define inf 1LL<<60

struct flower{
int hi;
int bty;
};
int solve(vector<flower>& v,int n)
{
    vector<int>dp(n+1);
    map<int,int>meaningful;
    dp[1]=v[1].bty;
    int ans = dp[1];
    meaningful[v[1].hi] = dp[1];

    for(int i=2;i<=n;i++)
    {
        dp[i] = v[i].bty;
         auto it = meaningful.lower_bound(v[i].h+1);

         if(it!=meaningful.begin())
         {
             it--;
             dp[i]+= it->second;
         }
         meaningful[v[i].hi] = dp[i];

         auto it = meaningful.upper_bound(v[i].h);

         while(it!=meaningful.end() && it->second<=dp[i])
         {
             auto temp = it;
             temp++;
             meaningful.erase(it);

             it = temp;
         }
        ans = max(ans,dp[i]);
    }

    return ans;
}
int32_t main()
{
	fast;
	int n;
    cin>>n;

    vector<flower>v(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i].hi;

    for(int i=1;i<=n;i++)
        cin>>v[i].bty;

    cout<<solve(v,n);

	return 0;
}

