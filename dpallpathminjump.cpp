#include<bits/stdc++.h>
using namespace std;
//top down
int dp[101];
// int solve(vector<int>&v,int n)
// {
//   if(n==1)
//   return 0;
  
//   if(dp[n]!=-1)
//   return dp[n];
  
//   int ans=INT_MAX;
//   for(int i=n-2;i>=0;i--)
//   {
//       if(i+v[i]>=n-1)
//       {
//           int subans=solve(v,i+1);
//           if(subans!=INT_MAX)
//           ans=min(ans,subans+1);
//       }
//   }
//   return dp[n]=ans;
// }
int main()
{
   // memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    //cout<<solve(v,n);
    
    
    //bottom up
    for(int i=n-2;i>=0;i--)
    {   int steps=v[i];
         int mn=INT_MAX;
        for(int j=1;j<=steps && i+j <n; j++)
        {
            if(dp[i+j]!=INT_MAX && dp[i+j]<mn)
            {
                mn=dp[i+j];
            }
        }
        if(mn!=INT_MAX)
        dp[i]=mn+1;
        else 
        dp[i]=INT_MAX;
    }
    
    cout<<dp[0]<<"\n";
    
    //print path
    
    queue<pair<pair<int,int >,pair<int ,string >> > q;
    string psf="0";
    q.push({{0,v[0]},{dp[0],psf}});
    
    while(!q.empty())
    {
        pair<pair<int,int >,pair<int ,string > >curr=q.front();
        q.pop();
        
        int i=curr.first.first;
        int steps=curr.first.second;
        int val=curr.second.first;
        string psf=curr.second.second;
        
        if(i==n-1)
        {
            cout<<psf<<"."<<"\n";
        }
        for(int j=1;j<=steps && i+j<n ;j++)
        {
            if(dp[i+j]!=INT_MAX && dp[i+j]==val-1)
            {
                psf.push_back('-');
                psf.push_back('>');
                psf+=(to_string(i+j));
              
                q.push({{i+j,v[i+j]},{dp[i+j],psf}}); 
            }
        }
    }
    
}