class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> st;
        priority_queue<int, vector<int>, greater<int>> en;
        
        for (int i=0;i<candidates;i++) {
            st.push(costs[i]);
        }
        for (int i= max(candidates, int(costs.size()-candidates));i<costs.size();i++) {
            en.push(costs[i]);
        }

        long ans = 0;
        int nxS = candidates;
        int nxE = costs.size() - 1 - candidates;

        for (int i = 0; i < k; i++) {
            if (en.size()==0 || !st.empty() && st.top() <= en.top()) {
                ans += st.top();
                st.pop();
                if (nxS <= nxE) {
                    st.push(costs[nxS]);
                    nxS++;
                }
            } 
            else {
                ans += en.top();
                en.pop();
                if (nxS <= nxE) {
                    en.push(costs[nxE]);
                    nxE--;
                }
            }
        }

        return ans;
    }
};