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
vector<vector<int> > v;
int dp[100007][3];
int solve(int i,int n,int curr)
{

	if(i>=n)
		return 0;

	if(dp[i][curr]!=-1)
		return dp[i][curr];
	// if(prev==-1)
	// {   
	// 	int op1=solve(i+1,n,0);
	// 	int op2=solve(i+1,n,1);
 //        int op3=solve(i+1,n,2);
 //        dp[i]=max(op1,max(op2,op3));b
	// }
	int ans=0;
    if(curr==0)
    {
    	int op1=v[i][0]+solve(i+1,n,1);
        int op2=v[i][0]+solve(i+1,n,2);
            ans=max(op1,op2);
        //dp[i][0]=max(op1,op2);
    }
    else if(curr==1)
    {
    	int op1=v[i][1]+solve(i+1,n,0);
        int op2=v[i][1]+solve(i+1,n,2);
            ans=max(op1,op2);
        //dp[i][1]=max(op1,op2);
    }
    else if(curr==2)
    {

    	int op1=v[i][2]+solve(i+1,n,0);
        int op2=v[i][2]+solve(i+1,n,1);
        ans=max(op1,op2);
         //cout<<op1<<" "<<op2<<"\n";
        //dp[i][2]=max(op1,op2);
    }
    //cout<<dp[i]<<"\n";
  //  return max(dp[i][0],max(dp[i][1],dp[i][2]));
    return dp[i][curr]=ans;
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
  	int a,b,c;
  	cin>>a>>b>>c;
  	v.pb({a,b,c});
  }
  int ans=0;
  //cout<<solve(0,n,-1)<<"\n";
  for(int i=0;i<3;i++)
  	 {   int val=solve(0,n,i);
  	 	//cout<<val<<" ";
  	 	ans=max(ans,val);
  	 }

  	cout<<ans<<"\n";
	return 0;
}