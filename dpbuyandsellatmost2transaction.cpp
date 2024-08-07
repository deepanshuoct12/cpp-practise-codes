class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>left(n),right(n);
        int mn=INT_MAX;
        int mxsell=0;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,prices[i]);
            
            left[i]=max(mxsell,prices[i]-mn);
            mxsell=left[i];
        }
        int mx=INT_MIN;
        int mxbuy=0;
         for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            
            right[i]=max(mxbuy,mx-prices[i]);
             mxbuy=right[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,left[i]+right[i]);
        }
        return ans;
    }
};