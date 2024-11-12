class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int firstNum = INT_MAX;
        int secondNum = INT_MAX;

        for(int i=0;i<n;i++) {
             int thirdNum = nums[i];

            // check for the first smallest number
            if(thirdNum <= firstNum) {
                firstNum = thirdNum;
            } else if (thirdNum <= secondNum) {
                // check for the second smallest number
                secondNum = thirdNum;
            } else {
                return true;
            }
        }

        return false;
    }
};
