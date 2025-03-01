class Solution {
public:
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        vis[entrance[0]][entrance[1]]=true;
        int lev=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                if(x==0 || x==n-1 || y==0 || y==m-1){
                    if(lev!=0) return lev;
                }
                
                for(int i=0;i<4;i++){
                    int ni=x+dir[i][0];
                    int nj=y+dir[i][1];
                    
                    
                    
                    if(ni>=0 && ni<n && nj>=0 && nj<m && maze[ni][nj]!='+' && vis[ni][nj]==false){
                        vis[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
                
            }
            lev++;
        }
        
        return -1;
    }
};