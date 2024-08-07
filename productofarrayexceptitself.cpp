class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int idx=-1;
        int c=0;

        vector<int>op(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                idx=i;
                c++;
                continue;
            }
            prod*=nums[i];
        }
        if(c==1)
        {
            op[idx]=prod;
            return op;
        }
        if(c>1)
            return op;

        for(int i=0;i<nums.size();i++)
        {
            op[i]=prod/nums[i];
        }
        return op;
    }
};
