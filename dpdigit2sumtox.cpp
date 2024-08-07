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
int arr[100007];
int dp[11][100][2];
//Time complexity=>2*11*100
//find sum of digit from 1 to number
int solve(int pos,int n,int sum,bool flag,int x)
{
	if(sum>x)
		return 0;
	if(pos>n)
		{ 
			if(sum==x)
				{ //cout<<sum<<"\n";
					return 1;
				}
			return 0;
		}

	if(dp[pos][sum][flag]!=-1)
		return dp[pos][sum][flag];

	int limit=9;
	if(flag==false)
		limit=arr[pos];
     int res=0;
	for(int i=0;i<=limit;i++)
	{
		if(flag || i<limit)
			res+=solve(pos+1,n,sum+i,true,x);
		else 
			res+=solve(pos+1,n,sum+i,false,x);
	}
	return dp[pos][sum][flag]=res;
}
int digitsum(string n)
{
	int sum=0;
	 for(int i=0;i<n.length();i++)
	 {
	 	sum+=n[i]-'0';
	 }
	return sum;
}
int32_t main()
{
   fast;
   init_code();
   int n;

    test
   { 
     int l,r,x;
     cin>>l>>r>>x;
     if(l!=0)
     l--;

   	string a,b;
    a=to_string(l);
    b=to_string(r);
   
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<a.length();i++)
    	arr[i+1]=a[i]-'0';

      int resa=solve(1,a.length(),0,0,x);

   	memset(dp,-1,sizeof(dp));
    for(int i=0;i<b.length();i++)
    	arr[i+1]=b[i]-'0';

      int resb=solve(1,b.length(),0,0,x);

     // int suma=digitsum(a);
      cout<<resb-resa<<"\n";//+suma<<"\n";
    
   }
	return 0;
}