class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]!=0) {
                swap(nums[j++],nums[i]);
            }
        }
    }
};
