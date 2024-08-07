#include<bits/stdc++.h>
using namespace std;

int dp[100];
//top down
int fun(string str,int i)
{
   // cout<<i<<" "<<str.length()<<"\n";
    if(i==str.length())
    return 1;

    if(dp[i]!=-1)
    return dp[i];

    if(str[i]=='0')
    return 0;

    int ans=fun(str,i+1);
  //  cout<<ans<<":"<<"\n";
    if(str.length()-i>=2){
    string sub=str.substr(i,2);
    int val=stoi(sub);
    if(val>=10 && val<=26)
    ans+=fun(str,i+2);
   // cout<<ans<<":::"<<"\n";
    }
    return dp[i]=ans;

}
//bottom up
int fun2(string str)
{
    int n=str.length();
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=str[0]=='0'?0:1;
    for(int i=2;i<=n;i++)
    {
        int one=stoi(str.substr(i-1,1));
        if(one>=1&& one<=9)
            dp[i]=dp[i]+dp[i-1];

        int two=stoi(str.substr(i-2,2));
        if(two>=10 && two<=26)
            dp[i]=dp[i]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    string str;
    memset(dp,-1,sizeof(dp));
    cin>>str;
    cout<<fun2(str);
    return 0;
}
