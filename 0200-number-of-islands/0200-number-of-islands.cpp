class Solution {
public:
    
    void bfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        visited[i][j] = true;
        
        queue<pair<int, int>>q;
        q.push({i, j});
        vector<pair<int, int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto it: directions){
                int row = x.first+it.first;
                    int col = x.second+it.second;
                    if(row>=0 && row<visited.size() && col>=0 && col<visited[0].size() && !visited[row][col] && grid[row][col] == '1'){
                        visited[row][col] = true;
                        q.push({row, col});
            }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};