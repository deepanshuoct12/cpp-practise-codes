#include<bits/stdc++.h>//top down doubt
using namespace std;
//int mx=-1;
int dp[1000];
int fun(vector<int>&v,int i,bool taken)
{
    if(i==v.size())
    {
        //mx=max(sum,mx);
        return 0;
    }
    if(dp[i]!=-1)
    return dp[i];

    if(taken==false)
    {
        dp[i]=max(v[i]+fun(v,i+1,true),fun(v,i+1,false));
    }
    else
    dp[i]=fun(v,i+1,false);
    return dp[i];
}
//bottom up
int fun2(vector<int>v)
{
    int n=v.size();
    vector<int>inc(n),exc(n);
    inc=v;
    exc[0]=0;
    for(int i=1;i<n;i++)
    {
        inc[i]+=exc[i-1];
        exc[i]=max(inc[i-1],exc[i-1]);
        //cout<<inc[i]<<"\n"<<exc[i]<<" ";
    }
    return max(inc[n-1],exc[n-1]);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
  //  memset(dp,-1,sizeof(dp));

    cout<<fun2(v)<<"\n";
     /*for(int i=0;i<n;i++)
    cout<<dp[i]<<" ";*/
   // cout<<mx;
    return 0;
}
