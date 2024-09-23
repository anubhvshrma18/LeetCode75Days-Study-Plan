// Sorting + Two Pointer
// T.C. - O(NLogN)
// S.C. - O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;
        int cnt = 0;

        while(l<r) {

            if(nums[l]+nums[r]==k) {
                cnt++;
                l++, r--;
            } else if(nums[l]+nums[r] < k){
                l++;
            } else {
                r--;
            }
        }

        return cnt;
    }
};


// Storing the Frequency of Numbers
// T.C. - O(N)
// S.C. - O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int, int> map;
        int res = 0;
        for (int n : nums) {
            if (map[k - n] > 0) {
                res++;
                map[k - n]--;
            } else {
                map[n]++;
            }
        }
        return res;
    }
};
