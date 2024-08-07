#include<iostream>
using namespace std;

int fib(int n)
{
    int dp[1000]={};

    dp[0]=0;
    dp[1]=1;

    for(int curnum=2;curnum<=n;curnum++)
    {
        dp[curnum]=dp[curnum-1]+dp[curnum-2];

    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);

}
