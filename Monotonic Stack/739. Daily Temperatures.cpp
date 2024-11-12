class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        
        ans[n-1]=0;
        st.push({T[n-1],n-1});
        
        for(int i=n-2;i>=0;i--) {
            
            while(!st.empty() && st.top().first<=T[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                ans[i]=0;
            } else {
                ans[i]=st.top().second - i;
            }
            st.push({T[i],i});
        }
        
        return ans;
        
    }
};