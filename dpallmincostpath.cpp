#include<bits/stdc++.h>
using namespace std;

 int dp[1005][1005];

int main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    vector<vector<int> >mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>mat[i][j];
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
            dp[i][j]=mat[i][j];
            else if(i==n-1)
            dp[i][j]=mat[i][j]+dp[i][j+1];
            else if(j==m-1)
            dp[i][j]=mat[i][j]+dp[i+1][j];
            else 
            {
                dp[i][j]=mat[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    
    queue<pair<string,pair<int,int> > > q;
    q.push({"",{0,0}});
    
    cout<<dp[0][0]<<"\n";
    while(!q.empty())
    {
        pair<string,pair<int,int> > curr=q.front();
        q.pop();
        
        int i=curr.second.first;
        int j=curr.second.second;
        string path=curr.first;
        
        if(i==n-1 && j==m-1)
        {
            cout<<path<<"\n";
        }else if(i==n-1)
        {
             q.push({path+"H",{i,j+1}});
        }else if(j==m-1){
             q.push({path+"V",{i+1,j}});
        }
        else {
            if(dp[i][j+1]<dp[i+1][j])
            q.push({path+"H",{i,j+1}});
            else if(dp[i][j+1]>dp[i+1][j])
             q.push({path+"V",{i+1,j}});
            else {
                  q.push({path+"V",{i+1,j}});
                  q.push({path+"H",{i,j+1}});
                
            } 
             
        }
    }
}