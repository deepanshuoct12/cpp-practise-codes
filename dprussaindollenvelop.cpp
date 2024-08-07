class Solution {
public:
int solve(vector<vector<int> > &v)
{
    int dp[5007];
    int ans=0;
    int n=v.size();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(v[j][1]<v[i][1] && v[j][0]<v[i][0])
            m=max(m,dp[j]);
        }
        dp[i]=m+1;
        ans=max(dp[i],ans);
    }
    return ans;
}
