#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int> > &v)
{
    int dp[101];
    int ans=0;
    int n=v.size();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(v[j].second<v[i].second)
            m=max(m,dp[j]);
        }
        dp[i]=m+1;
        ans=max(dp[i],ans);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    });
    cout<<solve(v);
}