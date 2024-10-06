class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        // for storing the rows/columns
        map<vector<int>,int> mp;

        for(int r=0;r<n;r++) {
            mp[grid[r]]++;
        }
        int count=0;
        // check for each column if it is map
        for(int c=0;c<n;c++) {
            vector<int> tempCol;
            for(int r=0;r<n;r++) {
                tempCol.push_back(grid[r][c]);
            }

            if(mp.find(tempCol)!=mp.end()) {
                count += mp[tempCol];
            }
        }

        return count;
    }
};
