#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void solve(vector<vector<int> >& v,int n,int m)
{
   memset(dp,0,sizeof(dp));

    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][j]=v[i][j];
            if(j+1<m)
            {
                int op1=0,op2=0;
                if(i-1>=0)
                op1=dp[i-1][j+1];
                if(i+1<n)
                op2=dp[i+1][j+1];
                
                dp[i][j]+=max(op1,max(op2,dp[i][j+1]));
            }
        
        }
    }
     
    //  for(int i=0;i<n;i++)
    //  {
    //      for(int j=0;j<m;j++)
    //      {
    //          cout<<dp[i][j]<<" ";
    //      }
    //      cout<<"\n";
    //  }
     int mx=0;
     for(int i=0;i<n;i++)
     {
         mx=max(mx,dp[i][0]);
     }
     cout<<mx<<"\n";
    queue<pair<pair<int,int>,string>  > q;
  
     for(int i=0;i<n;i++)
     {
         if(dp[i][0]==mx)
          q.push({{i,0},to_string(i)+" "});
     }
    
     while(!q.empty())
     {
         pair<pair<int,int>,string> curr=q.front();
         q.pop();
         string psf=curr.second;
         int i=curr.first.first;
         int j=curr.first.second;
         
         
         if(j==m-1)
         {
             cout<<psf<<"\n";
         }
         int mx2=0;
        
         if(j+1<m){
             
          for(int k=-1;k<=1;k++)
         { 
             mx2=max(mx2,dp[i+k][j+1]);
         }
         
         
         if(i-1>=0 && dp[i-1][j+1]==mx2)
         {  
              q.push({{i-1,j+1},psf+"d1 "});
         }
          if(i+1<n && dp[i+1][j+1]==mx2)
         {  
              q.push({{i+1,j+1},psf+"d3 "});
         }
          if(dp[i][j+1]==mx2)
         {  
              q.push({{i,j+1},psf+"d2 "});
         }
         }
     }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>v[i][j];
    }
    solve(v,n,m);
    return 0;
}