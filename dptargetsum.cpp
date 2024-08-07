#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//bottom up
bool subsetsum(vector<int>&v,int n,int sum)
{
    for(int i=0;i<sum;i++)
    dp[0][i]=0;

    for(int i=0;i<n;i++)
    dp[i][0]=1;

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(v[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
        }
    }
   return dp[n][sum];
}
//topdown
bool subsetsumtopdown(vector<int>&v,int n,int sum)
{
    if(sum==0)
    return 1;

    if(n==0)
    return 0;

     if(dp[n][sum]!=-1)
     return dp[n][sum];

    if(v[n-1]>sum)
    dp[n][sum]=subsetsumtopdown(v,n-1,sum);
    else
    dp[n][sum]=(subsetsumtopdown(v,n-1,sum)||subsetsumtopdown(v,n-1,sum-v[n-1]));

    return dp[n][sum];
}

int main(){
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    int sum;
    cin>>sum;
     if(subsetsumtopdown(v,n,sum))
     cout<<"true";
     else
     cout<<"false";

}
