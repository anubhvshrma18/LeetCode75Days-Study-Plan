class Solution {
public:
    void dfs(vector<vector<int>>& G, int cN, int pN, vector<int>& vis) { 
        vis[cN]=true;
        for(auto a:G[cN]) {
            if(!vis[a] && a!=pN) {
                dfs(G, a, cN, vis);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<int> vis(V,0);
        
        dfs(rooms, 0, 0, vis);
        
        for(auto a:vis) {
            if(a==0) {
                return false;
            }
        }
        return true;
    }
};