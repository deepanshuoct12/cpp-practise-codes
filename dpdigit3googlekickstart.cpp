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
int dp[20][2][2][2];
int solve(string &R,int n,bool even,bool leading,bool tight)
{
	if(n==0)
		return 1;
       
     if(dp[n][even][leading][tight]!=-1)
     	return dp[n][even][leading][tight];



	if(even)
	{   vector<int>digits={0,2,4,6,8};
		int ub=tight?(R[R.length()-n]-'0'):9;
	     int ans=0;
	   for(auto d:digits)
	   {
	   	if(d<=ub)
	   	{
          ans+=solve(R,n-1,0,0,(tight&(d==ub)));
	   	}
	   }
	   return dp[n][even][leading][tight]=ans;
	}
	else{
		vector<int>digits={1,3,5,7,9};
		int ub=tight?(R[R.length()-n]-'0'):9;
	     int ans=0;
	     if(leading==1)
	     {
	     	ans+=solve(R,n-1,0,1,0);
	     }

	    for(auto d:digits)
	   {
	   	if(d<=ub)
	   	{
          ans+=solve(R,n-1,1,0,(tight&(d==ub)));
	   	}
	   }
	   return dp[n][even][leading][tight]=ans;
	}

}
int32_t main()
{
   fast;
   init_code();
   int n;
   int tm=1;
   test
   {
   	memset(dp,-1,sizeof(dp));
      int l,r;
      cin>>l>>r;
      if(l!=0)
      	l--;

      string L=to_string(l);
      string R=to_string(r);

          int ans1=solve(R,R.length(),0,1,1);
           	memset(dp,-1,sizeof(dp));
           	int ans2=solve(L,L.length(),0,1,1);
      cout<<"Case #"<<tm<<": "<<ans1-ans2<<"\n";
      tm++;
   }
	return 0;
}