#include<bits/stdc++.h>
using namespace std;
int dp[1001][12];
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
//O(n*n*n)
int solve(int n,int k,vector<vector<int> > &v)
{
    for(int i=0;i<k;i++)
    dp[0][i]=v[0][i];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k;j++)
         {
             dp[i][j]=v[i][j];
             int mn=INT_MAX;
             for(int m=0;m<k;m++)
             {
                 if(m==j)
                 continue;
                 
                 mn=min(mn,dp[i-1][m]);
             }
             
             dp[i][j]+=mn;
         }
    }
    
    int ans=INT_MAX;
   for(int i=0;i<k;i++)
     ans=min(ans,dp[n-1][i]);
     
     return ans;
}
//O(n*n)
int solve2(vector<vector<int> > &v,int k)
{
    int n=v.size();
    int least=INT_MAX;
    int sleast=INT_MAX;
    
    for(int i=0;i<k;i++)
    {
        dp[0][i]=v[0][i];
        if(v[0][i]<=least)
        {
            sleast=least;
            least=v[0][i];
        }
        else if(v[0][i]<=sleast)
        {
            sleast=v[0][i];
        }
    }
    
    for(int i=1;i<n;i++)
    {
        int nleast=INT_MAX;
        int nsleast=INT_MAX;
        for(int j=0;j<k;j++)
        {
            dp[i][j]=v[i][j]+(least==dp[i-1][j]?sleast:least);
            
        if(dp[i][j]<=nleast)
        {
            nsleast=nleast;
            nleast=dp[i][j];
        }
        else if(dp[i][j]<=nsleast)
        {
            nsleast=dp[i][j];
        }
        }
        least=nleast;
        sleast=nsleast;
    }
    return least;
}
int main()
{
    init_code();
    int n,k;
    cin>>n>>k;
    vector<vector<int> > v(n,vector<int>(k));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        cin>>v[i][j];
    }
    cout<<solve2(v,k);
  
    
    return 0;
}