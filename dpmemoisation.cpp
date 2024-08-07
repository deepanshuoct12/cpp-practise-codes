#include<iostream>
using namespace std;

int memo[1000];
int fibonacci(int n)     // n is the n'th fibonacci  that we need to calculate
{
    if(n==0 || n==1)
        return 1;

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    int ans=fibonacci(n-1)+fibonacci(n-2);
    memo[n]=ans;

    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        memo[i]=-1;

    cout<<fibonacci(n);
}
