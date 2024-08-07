#include<iostream>           // HOW YO DO IT WITH DP??
#include<algorithm>
using namespace std;
int memo[100];
int dp[100];
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
int main()
{
    int n;
    cin>>n;


    cout<<noofways(n);
    return 0;
}
