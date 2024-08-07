class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<vector<int> > dp(k+1,vector<int>(n+1,0));
        //O(n*n*n)
//         for(int i=1;i<=k;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 dp[i][j]=dp[i][j-1];
                
//                 for(int p=0;p<j;p++)
//                 {
//                     dp[i][j]=max(dp[i][j],dp[i-1][p]+(prices[j] - prices[p]));
//                 }
//             }
//         }
//         return dp[k][n-1];
        
        //O(n*n)
         for(int i=1;i<=k;i++)
        {
             int mx=INT_MIN;
            for(int j=1;j<n;j++)
            {
                if(dp[i-1][j-1]-prices[j-1]>mx)
                    mx=dp[i-1][j-1]-prices[j-1];
                
                dp[i][j]=max(dp[i][j-1],mx+prices[j]);
            }
        }
        return dp[k][n-1];
    }
};