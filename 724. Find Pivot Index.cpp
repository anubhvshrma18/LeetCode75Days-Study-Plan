class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0, pi = -1;
        for(int i=0;i<n;i++) {
            rightSum += nums[i];
        }
        for(int i=0;i<n;i++) {
            // subtract ith element from the total sum
            rightSum = rightSum - nums[i];
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return pi;
    }
};
