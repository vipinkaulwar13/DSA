class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int rec(int i, int j, vector<vector<int>>& grid) {
        if (j == m - 1)
            return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (i > 0 && j < m - 1 && grid[i - 1][j + 1] > grid[i][j])
            ans = max(ans, (1 + rec(i - 1, j + 1, grid)));

        if (j < m - 1 && grid[i][j + 1] > grid[i][j])
            ans = max(ans, 1 + rec(i, j + 1, grid));

        if (i < n - 1 && j < m - 1 && grid[i + 1][j + 1] > grid[i][j])
            ans = max(ans, 1 + rec(i + 1, j + 1, grid));
            
        return dp[i][j] = ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = rec(i, 0, grid);
            ans = max(ans, x);
        }
        return ans;
    }
};