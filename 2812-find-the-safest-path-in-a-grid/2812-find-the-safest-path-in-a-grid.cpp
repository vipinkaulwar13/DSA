// class Solution {
// public:
//     vector<int> a;
//     int minn = INT_MAX;
//     int solve(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>>& cds){
//         int n = grid.size();
//         int m = grid[0].size();
//         if(x<0 || y<0 || x>=n || y>=m || grid[x][y] == 1) return 0;
//         for(int i = 0; i<cds.size(); i++){
//             int dist = abs(x-cds[i].first) + abs(y-cds[i].second);
//             minn = min(minn, dist);
//         }
//         if(x == n-1 && y == m-1) return minn;
        
//         int res = 0;
//         res = min({solve(grid, x-1, y, cds), solve(grid, x, y-1, cds), solve(grid, x+1, y, cds), solve(grid, x, y+1, cds)});
//         a.push_back(res);
        
//         return 0;
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         vector<pair<int,int>> cds;
//         if(grid[0][0] == 1 || grid[grid.size()][grid[0].size()] == 1) return 0;
        
//         for(int i = 0; i<grid.size(); i++){
//             for(int j = 0; j<grid[0].size(); j++){
//                 if(grid[i][j] == 1) cds.push_back({i,j});
//             }
//         }
//         solve(grid, 0, 0, cds);
//         int maxx = 0;
        
//         for(int i = 0; i<a.size(); i++){
//             maxx = max(a[i], maxx);
//         }
        
//         return maxx;
//     }
// };

class Solution{
    public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        auto [sf, i, j] = pq.top(); pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return pq.top()[0] - 1;
  }
};
