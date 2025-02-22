class Solution {
public:
    int rob(vector<int>& N) {
        int n=N.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=N[0];
        for(int i=2;i<=n;i++) {
            dp[i] = max(dp[i-1], N[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};