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
int memo[1001][1001];
int solve(vector<int>&v)
{
    int dp[100][100];
    memset(dp,0,sizeof dp);

    int n = v.size()-1;

    for(int i=1;i<n;i++){
       int r=0,c=i;
        while(c<n){
        int val=INT_MAX;
        for(int pivot=r;pivot<c;pivot++){
        val = min(val,dp[r][pivot]+dp[pivot+1][c] + v[r]*v[pivot+1]*v[c+1]);

        }

        dp[r][c]=val;
           r++,c++;
        }
    }

//   for(int i=0;i<4;i++){
//       for(int j=0;j<4;j++)
//       {
//           cout<<dp[i][j]<<" ";
//       }
//       cout<<"\n";
//   }
    return dp[0][n-1];
}

//top down
int matrixchain(vector<int>&v,int i,int j)
{
   if(i==j)
    {   
        memo[i][j]=0;
        return 0;
    }
   if(memo[i][j]!=-1)
    return memo[i][j];

  int ans=INT_MAX;
  for(int k=i;k<j;k++)
  {
    int temp=matrixchain(v,i,k)+matrixchain(v,k+1,j)+(v[i-1]*v[k]*v[j]);
    ans=min(ans,temp);
  }
  return memo[i][j]=ans;
}

//bottom up
int matrixchain2(vector<int>&v)
{
   int n=v.size();
   int dp[n+1][n+1];
   memset(dp,0,sizeof(dp));
   for(int i=1;i<n;i++)
    dp[i][i]=0;
   for(int len=2;len<n;len++)
   {
    for(int start=1;start<=n-len;start++)
    {
        int end=start+len-1;
            dp[start][end]=INT_MAX;
            for(int k=start;k<end;k++)
            {
                dp[start][end]=min(dp[start][end],dp[start][k]+dp[k+1][end]+(v[start-1]*v[k]*v[end]));
            }
        
    }
   }

   return dp[1][n-1];
}
int32_t main(){
    init_code();
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}

//cout<<solve(v);
//top down
// memset(memo,-1,sizeof(memo));
// cout<<matrixchain(v,1,v.size()-1);

//bottom up
cout<<matrixchain2(v);
return 0;
}
