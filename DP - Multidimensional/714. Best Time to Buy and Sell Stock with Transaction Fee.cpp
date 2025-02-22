class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        int dp[n][2];
        dp[0][0]=-arr[0];
        dp[0][1]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][1]-arr[i]);
                }
                else{
                    if(fee<dp[i-1][0]+arr[i]){
                        dp[i][j]=max(dp[i-1][j],dp[i-1][0]+arr[i]-fee);
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                
            }
            
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};