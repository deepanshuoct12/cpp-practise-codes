#include<bits/stdc++.h>         
using namespace std;
int memo[100];
int dp[100];
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
//bottom up
int noofways(int n)
{
    dp[00]={};
    //DP SOLUTION;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }

    return dp[n];

}
//top down
int noofways2(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;

      if(memo[n]!=-1)
        return memo[n];

    int ans=noofways2(n-1)+(n-1)*noofways2(n-2);
    return memo[n]=ans;
}
int main()
{
    init_code();
    int n;
    cin>>n;

   memset(memo,-1,sizeof(dp));
    cout<<noofways2(n);
    return 0;
}
