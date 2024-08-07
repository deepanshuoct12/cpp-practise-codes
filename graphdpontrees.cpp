#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100];
int dp[100];
void dfs(int curr,int par)
{
    dp[curr]=curr;
    for(auto x:graph[curr])
    {
        if(x!=par)
        {
            dfs(x,curr);
            dp[curr]=min(dp[curr],dp[x]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);

    for(int i=1;i<=n;i++)
        cout<<i<<" "<<dp[i]<<"\n";

return 0;
}
