class Solution {
public:
    void dfs(vector<vector<int>> graph,vector<bool> &vis,int src){
        vis[src]=true;
        for(int i:graph[src]){
            if(!vis[i]){
                dfs(graph,vis,i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& g) {
        // map<int,int> mp;
        int n=g.size();
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1 && i!=j){
                    graph[i].push_back(j);
                }
            }
        }
        
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(graph,vis,i);
                cnt++;
            }
        }
        
        return cnt;
    }
};