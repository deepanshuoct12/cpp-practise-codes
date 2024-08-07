#include<bits/stdc++.h>
using namespace std;
#define int long long int

int dp[1005][1005][12][2];
string s,t;
int n,m,k;
int solve(int is,int it,int rem,int cont){

if(is==n || it==m){
    return (rem==0?0:INT_MIN);
}

if(rem==0)
    return 0;

if(dp[is][it][rem][cont]!=-1)
    return dp[is][it][rem][cont];

    int ret = INT_MIN;
    ret = max(ret,solve(is+1,it,rem-cont,0));
    ret = max(ret,solve(is,it+1,rem-cont,0));

        if(s[is]==t[it])
        {
             ret = max(ret,1+solve(is+1,it+1,rem,1));
                ret = max(ret,1+solve(is+1,it+1,rem-1,0));
        }

    return dp[is][it][rem][cont]=ret;
}

int32_t main(){

cin>>n>>m>>k;
cin>>s>>t;
memset(dp,-1,sizeof dp);
cout<<solve(0,0,k,0);

return 0;
}
