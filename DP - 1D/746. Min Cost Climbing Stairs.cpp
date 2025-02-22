class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step1 = cost[0];
        int step2 = cost[1];
        int ans = 0;
        for(int i=2;i<cost.size();i++) {
            ans = min(step1, step2)+cost[i];
            step1=step2;
            step2=ans;
        }
        return min(step1,step2);
        
    }
};