class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int mn=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            mn=min(mn,prices[i]);
          
            if(prices[i]-mn>=ans)
                ans=prices[i]-mn;
        }
        return ans;
    }
};