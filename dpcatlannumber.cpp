#include<bits/stdc++.h>
using namespace std;
//top down
unsigned long long int solve(unsigned long long int n)
{
    if(n<=1)
    return 1;
    int res=0;
    for(int i=0;i<n;i++)
    res+=solve(i)*solve(n-i-1);

    return res;
}
//bottom up
unsigned long long int solve2(unsigned long long int n) {
  
        unsigned long long int dp[n+1];
         memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]=dp[i]+dp[i-j-1]*dp[j];
            }
            //cout<<dp[i]<<" ";
        }
        return dp[n];
    }
int main()
{
  unsigned long long int n;
    cin>>n;
    cout<<solve(n);
}
