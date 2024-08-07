#include<bits/stdc++.h>
using namespace std;
int dp[101];
int solve(int n)
{
    if(n==1 || n==2)
    return n;
    if(dp[n]!=-1)
    return dp[n];
    
    return dp[n]=solve(n-1)+solve(n-2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<solve(n);
    
}