class Solution {
public:
    vector<pair<int,int>>dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited){
    
        int n = grid.size();
        int m = grid[0].size();
        
        visited[x][y] = 1;
        
        for(int i = 0; i<4; i++){
            int nex = x+dirs[i].first;
            int ney = y+dirs[i].second;
            
            if(nex>=0 && ney>=0 && nex<n && ney<m && !visited[nex][ney] && grid[nex][ney]){
                dfs(nex, ney, grid, visited);
            }
        }
    }
    int cntislands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        vector<vector<int>>visited(n, vector<int>(m, 0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j]){
                    dfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int isdc = cntislands(grid);
        if(isdc>1 || isdc == 0) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    int cnt = cntislands(grid);
                    grid[i][j] = 1;
                    if(cnt >1 || cnt == 0) return 1;
                }
            }
        }
        return 2;
    }
};