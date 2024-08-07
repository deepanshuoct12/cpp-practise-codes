class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));

        for(int len=0;len<n;len++)
        {
            for(int start=0;start<n-len;start++)
            {
                int end=start+len;

                if(len==0)
                    dp[start][end]=0;
                else if(len==1)
                    dp[start][len]=0;
                else if(len==2)
                {
                    dp[start][end]=(values[start])*(values[start+1])*(values[start+2]);
                }
                else
                {   int mn=INT_MAX;
                    for(int k=start+1;k<=end-1;k++)
                    {
                        int tri=values[start]*values[k]*values[end];
                        int left=dp[start][k];
                        int right=dp[k][end];
                        int total=tri+left+right;
                        mn=min(mn,total);
                    }
                 dp[start][end]=mn;
                }
            }
        }
        return dp[0][n-1];
    }
};
