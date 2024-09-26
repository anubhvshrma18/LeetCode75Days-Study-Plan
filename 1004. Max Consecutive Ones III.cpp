class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int start = 0 , end =0 , n = nums.size();
        while(end < n) {
            if(nums[end] == 0) k--;

            if(k < 0) {
                if(nums[start] == 0) k++;
                start++;
            }
            end++;
        }

        return end-start;
    }
};
