class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        long sum = 0;
        // first window
        for(int i=0;i<k;i++) {
            sum += nums[i];
        }
        long maxSum = sum;

        for(int i=k;i<n;i++) {
            sum = sum - nums[i-k] + nums[i];
            maxSum = max(sum, maxSum);
        }

        return (double)maxSum/k;

    }
};
