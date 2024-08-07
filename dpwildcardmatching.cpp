class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=false;
        }
         for(int j=1;j<=m;j++)
        {
             if(p[j-1]=='*')
            dp[0][j]=dp[0][j-1];
             else
            dp[0][j]=false;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]|=dp[i-1][j]|dp[i][j-1];
                    // for(int k=i;k>=0;k--)
                    // {
                    //     dp[i][j]|=dp[k][j-1];
                    // }
                }
                else
                    dp[i][j]=false;

            }
        }
       // cout<<n<<" "<<m<<"\n";
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        return dp[n][m];
    }
};
