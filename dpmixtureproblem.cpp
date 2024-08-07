#include<bits/stdc++.h>
using namespace std;
int arr[1000];
long long dp[1000][1000];

long long sum(int s,int e)
{
    long long ans=0;
    for(int i=s;i<=e;i++)
    {
        ans+=arr[i];
        ans%=100;
    }
    return ans;
}

long long solvemixtures(int i,int j)
{
    if(i==j)  // if only one mixture is there it's smoke is 0
        return 0;

    //if the answer is already there
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=INT_MAX;

    for(int k=i;k<=j;k++) // break expression at every k
    dp[i][j]=min(dp[i][j],solvemixtures(i,k)+solvemixtures(k+1,j)+sum(i,k)*sum(k+1,j));

    return dp[i][j];


}

int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\n";

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }


    cout<<solvemixtures(0,n-1);
    return 0;
}
