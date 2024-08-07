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
int dp[3005][3005];
int lcs(string& X,string& Y)
{
    int m=X.length();
    int n=Y.length();
    
  memset(dp,0,sizeof(dp));
  
  
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
          if(X[i-1]==Y[j-1]) // WE DOSEN'T DO X[I]==Y[J] AS IN DP TABLE DP TABLE INDEXES ARE 1 LESS THAN M*N TABLE
            {
                dp[i][j]=1+dp[i-1][j-1];

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }

        }
    }
    return dp[m][n];
}
string getlcs(string s1,string s2){
   
    int len=lcs(s1,s2);
    int i=s1.length(),j=s2.length();
    string ans;
    ans.resize(len);
    int k=len-1;
    //cout<<len<<"\n";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans[k--]=s1[i-1];
            i--;
            j--;
           
        }
        else 
        {
            if(dp[i][j-1]>dp[i-1][j])
              j--;
            else 
            i--;
        }
    }
  
    return ans;
}
int32_t main()
{
   fast;
  // init_code();
   string s1,s2;
   cin>>s1>>s2;
   cout<<getlcs(s1,s2);
    return 0;
}


