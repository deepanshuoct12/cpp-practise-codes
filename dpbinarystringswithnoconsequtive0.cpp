#include<bits/stdc++.h> //top down dosent work
using namespace std;
int dp[1000];
//top down
int solve2(int n,string str,int i)
{
    if(i==n)
    {
        return 1;
    }

    if(dp[i]!=-1)
    return dp[i];


    if(str[i-1]=='0')
    {
        str[i]='1';
        dp[i]=solve2(n,str,i+1);
    }
    else if(str[i-1]=='1')
    {
        str[i]='0';
         int ans1=solve2(n,str,i+1);
        str[i]='1';
        int ans2=solve2(n,str,i+1);

        dp[i]=ans1+ans2;
    }
    return dp[i];
}
int solve(int n)
{

    string str;
    str.resize(n);
    //  dp[0]=1;
    str[0]='0';
    int ans1=solve2(n,str,1);
    str[0]='1';
    int ans2=solve2(n,str,1);
    cout<<ans1<<" "<<ans2<<"\n";
    for(int i=0;i<n;i++)
    cout<<dp[i]<<" ";
    cout<<"\n";
    return ans1+ans2;
}
//bottom up
int countbinary(int n)
{
    vector<int>one(n+1),zero(n+1);
    one[1]=1;
    zero[1]=1;

    for(int i=2;i<=n;i++)
    {
        one[i]=one[i-1]+zero[i-1];
        zero[i]=one[i-1];
    }
    return one[n]+zero[n];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<countbinary(n);

}
