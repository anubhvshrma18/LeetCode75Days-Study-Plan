class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0, k =1;
        while(i<n) {

            if(nums[i] == 0) {
                // we have encountered the required element that need to be removed
                k--;
            }

            if(k<0) {
                // we have more than 1 element in our window
                if(nums[j]==0) {
                    // we will remove this element from our window and update current elements in
                    // our window
                    k++;
                }
                j++;
            }
            i++;
        }

        // i-j - window size
        // removing 1 is required as per question
        return i-j-1;
    }
};
