class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if(n==0)
            return -1;
        if(n==1)
        {
            if(gas[0]>=cost[0])
                return 0;
            return -1;
        }
        int start=0;
        int end=1;
        int curr=(gas[start]-cost[start]);
        while(start!=end || curr<0)
        {
            while(curr<0 && start!=end)
            {
                curr-=(gas[start]-cost[start]);
                start=(start+1)%n;

                if(start==0)
                    return -1;
            }
          curr+=(gas[end]-cost[end]);
            end=(end+1)%n;
        }
        return start;
    }
};
