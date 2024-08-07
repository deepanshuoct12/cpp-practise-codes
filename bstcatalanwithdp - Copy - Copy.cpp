
#include<iostream>
using namespace std;
int dp[100];
int catalan(int n)      // catlan gives no. of bst's
{
    if(n==0)
        return 1;

        if(dp[n]!=0)
            return dp[n];
int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=catalan(i-1)*catalan(n-i);

    }
    dp[n]=ans;
    return ans;
}

int main()
{
    cout<<"catlan series is"<<"\n";

    for(int i=0;i<=10;i++)
        cout<<catalan(i)<<" ";

    return 0;
}
