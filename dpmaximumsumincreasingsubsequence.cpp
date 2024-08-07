#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
//top down
int helper(vector<int>&v,int n,int prev,int curr)
{
    if(curr==n)
    return 0;
    
    if(dp[prev+1][curr]!=-1)
    return dp[prev+1][curr];
    
    if(prev<0 || v[curr]>=v[prev])
    {
    dp[prev+1][curr]=max(v[curr]+helper(v,n,curr,curr+1),helper(v,n,prev,curr+1));
    }
    else 
    dp[prev+1][curr]=helper(v,n,prev,curr+1);
    
    return dp[prev+1][curr];
}
//bottom up
// int solve(vector<int>&v,int n)
// {
//     vector<int>dp(n,0);
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         int mx=0;
//         for(int j=0;j<i;j++)
//         {
//             if(v[j]<=v[i])
//             mx=max(mx,dp[j]);
//         }
//         dp[i]=mx+v[i];
//         ans=max(ans,dp[i]);
//     }
//     return ans;
// }
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    
    cout<<helper(v,n,-1,0);
    
}