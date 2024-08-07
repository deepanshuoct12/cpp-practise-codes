class Solution {
public:
    int dp[5007][2][2];
    int helper(int i,vector<int>&prices,bool own,bool cool)
    {
        if(i>=prices.size())
            return 0;
         
        if(dp[i][own][cool]!=-1)
          return dp[i][own][cool];
        
        if(cool)
        {
            dp[i][own][cool]=helper(i+1,prices,own,!cool);
        }
        else if(own==false)
        {
            dp[i][own][cool]=max(-prices[i]+helper(i+1,prices,!own,cool),helper(i+1,prices,own,cool));
        }
        else {
            dp[i][own][cool]=max(prices[i]+helper(i+1,prices,!own,!cool),helper(i+1,prices,own,cool));
        }
        
        return dp[i][own][cool];
    }
    int maxProfit(vector<int>& prices) {
         memset(dp,-1,sizeof(dp));
        return helper(0,prices,false,false);
        
//         int n=prices.size();
//         vector<int>buy(n),sell(n),cooldown(n);       
//         buy[0]=-prices[0];
//         sell[0]=0;
//         cooldown[0]=0;
//         for(int i=1;i<n;i++)
//         {
//             buy[i]=max(buy[i-1],cooldown[i-1]-prices[i]);
//             sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
//             cooldown[i]=sell[i-1];
//         }       
//         return sell[n-1];
    }
    
};