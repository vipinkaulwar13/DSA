class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y] <=0) return 0;
        grid[x][y] = -grid[x][y];
        int res = max({solve(grid, x-1, y), solve(grid, x, y-1), solve(grid, x+1, y), solve(grid, x, y+1)});
        grid[x][y] = -grid[x][y];
        return grid[x][y]+res;
        
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res = max(res,solve(grid, i, j));
            }
        }
        return res;
    }
};