class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int s=spells[i];
            int l=0, r = m-1;
            while(l<=r) {
                int mid = l+ (r - l) / 2;
                long long p = (long long)s * (long long)potions[mid];
                if (p >= success) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = m - l;
        }
        return ans;
    }
};