#include<bits/stdc++.h>
using namespace std;
int spot[100007];
int dp[100007];
//top down
int helper(int m,int i,int t)
{
    if(i>m)
    return 0;
    
    if(dp[i]!=-1)
    return dp[i];
    
    if(spot[i]>0)
    {
        dp[i]=max(spot[i]+helper(m,i+t+1,t),helper(m,i+1,t));
    }
    else
    {
     dp[i]= helper(m,i+1,t);
    }
    return dp[i];
}

// //O(n*n)
// int solve(vector<int>v,int t,vector<int>revenue)
// {
//     int n=v.size();
//     vector<int>dp(n,0);
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         int mx=0;
//         for(int j=0;j<i;j++)
//         {
//             if(v[i]-v[j]>t)
//             mx=max(mx,dp[j]);
//         }
//         dp[i]=mx+revenue[i];
//         ans=max(ans,dp[i]);
//     }
//     return ans;
// }

int solve2(int m,int t)
{
    for(int i=1;i<=m;i++)
    {
      //  cout<<spot[i]<<" ";
        if(spot[i]>0)
        {
          int exc=dp[i-1];
          int inc=(i>=t+1)?dp[i-t-1]:0;
          inc=inc+spot[i];
          dp[i]=max(exc,inc);
        }
        else 
        dp[i]=dp[i-1];
    }
   // cout<<"\n";
    return dp[m];
}
int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    memset(spot,0,sizeof(spot));
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    vector<int>revenue;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        revenue.push_back(x);
      
    }
    for(int i=0;i<n;i++)
     spot[v[i]]=revenue[i];
     
    int t;
    cin>>t;
    
     cout<<helper(m,1,t)<<"\n";
  
  //  cout<<solve2(m,t);
    
}