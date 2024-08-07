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
int people[11][101];
int dp[101][1025];
int solve(int shirt,int mask,int n)
{
	if(mask==(1<<n)-1)
		return 1;

	if(shirt>100)
		return 0;

	if(dp[shirt][mask]!=-1)
		return dp[shirt][mask];

   int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(mask & (1<<(i-1)))
			continue;

		if(people[i][shirt]>0)
		{
          ans=(ans+solve(shirt+1,(mask|(1<<(i-1))),n)%mod)%mod;
		}
	}
    ans=(ans+solve(shirt+1,mask,n)%mod)%mod;

    return dp[shirt][mask]=ans;
}
void in(int n)
{
    string s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in>>a)
        {
            people[i+1][a] = 1;
        }
    }
}
int32_t main()
{
   fast;
   init_code();
   int n;

   test
   {
   	 memset(people,0,sizeof(people));
   memset(dp,-1,sizeof(dp));
    cin>>n;
    in(n);
    // for(int i=1;i<=n;i++)
    // {
    // 	int shirt;
    // 	while((cin>>shirt))
    // 	{
    // 		cout<<shirt<<" ";
    //      	people[i][shirt]=1;
    //      }

    //      cout<<"\n";
    // }

    cout<<solve(1,0,n)<<"\n";
   }
	return 0;
}