class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // nums[-1]=INT_MIN,nums[n]=INT_MIN;
        
        int l=0,h=n-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(m==0 && nums[m]>nums[m+1]){
                return m;
            }
            if(m>0 &&  nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }
            
            if(m==n-1 && nums[m]>nums[m-1]){
                return m;
            }
            
            
            if(nums[l] > nums[m]){
                h--;
            }
            else{
                l++;
            }
        }
        
        return l;
    }
};