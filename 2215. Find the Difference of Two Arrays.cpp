class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> diff1;
        for (int num : s1) {
            if (s2.count(num) == 0) {
                diff1.push_back(num);
            }
        }

        vector<int> diff2;
        for (int num : s2) {
            if (s1.count(num) == 0) {
                diff2.push_back(num);
            }
        }

        return {diff1, diff2};
    }
};
