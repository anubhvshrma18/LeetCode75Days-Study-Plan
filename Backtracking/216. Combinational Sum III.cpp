class Solution {
public:
    void comp(vector<vector<int>>& ans, vector<int>& cand, int cn, int tn, int cs, int ts) {
        if(cs > ts || cn > 10) {
            return;
        }
        if(cs == ts) {
            if(tn==0) {
                ans.push_back(cand);
            }
            return;
        }
        for(int i=cn;i<ts;i++) {
            cand.push_back(i);
            comp(ans, cand, i+1, tn-1,cs+i, ts);
            cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        comp(ans,v, 1, k, 0, n);
        return ans;
    }
};