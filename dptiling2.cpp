#include<bits/stdc++.h>
using namespace std;
//top down
int dp[1001];
int solve(int n,int m)
{
    if(n<m)
    return 1;
     if(dp[n]!=-1)
     return dp[n];
     
    return dp[n]=solve(n-1,m)+solve(n-m,m);
   
}
//bottom up
int solve2(int n,int m)
{
    dp[0]=0;
   for(int i=1;i<=n;i++)
   {
       if(i<m)
       dp[i]=1;
       else if(i==m)
       dp[i]=2;
       else 
       dp[i]=dp[i-1]+dp[i-m];
   }
   return dp[n];
}
int main()
{
  //  memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    cout<<solve2(n,m);
}