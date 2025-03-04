class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& I) {
        if(I.size()==1) return 1;
        sort(I.begin(),I.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        
        int cnt = 0;
        int pre = I[0][1];
        for(int i=1;i<I.size();i++) {

            if(I[i][0] <= pre)
                cnt++;
            else{
                pre = I[i][1];
            }
        }
        return I.size()-cnt;
    }
};