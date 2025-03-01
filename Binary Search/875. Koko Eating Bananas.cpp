class Solution {
public:
    bool possible(vector<int>& piles, int k, int h) {
        long cnt=0;
        for(int p:piles) {
            cnt+=p/k;
            cnt+=(p%k!=0)? 1:0;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, hi=*max_element(piles.begin(), piles.end());
        while(l<=hi) {
            int m = l+((hi-l)/2);
            if(possible(piles, m, h)) {
                hi = m-1;
            } else {
                l = m+1;
            }
        }
        return l;
    }


};