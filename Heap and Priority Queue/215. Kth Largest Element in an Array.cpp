class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(pq.size()>k) {
                while(pq.size()>k-1 && pq.top() < nums[i]) {
                    pq.pop();
                }
                if(pq.size()<k) {
                    pq.push(nums[i]);
                }
                
            } else {
                pq.push(nums[i]);
            }
            
        }
        while(pq.size()>k) {
            pq.pop();
        }
        return pq.top();
    }
};