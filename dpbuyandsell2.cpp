class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         int b=0,s=0;
        int profit=0;
        for(int i=1;i<n;i++)
        {
           if(prices[i]>=prices[i-1])
               s++;
            else 
            {
                profit+=(prices[s]-prices[b]);
                b=s=i;
            }
        }
           profit+=(prices[s]-prices[b]);
        return profit;
    }
};