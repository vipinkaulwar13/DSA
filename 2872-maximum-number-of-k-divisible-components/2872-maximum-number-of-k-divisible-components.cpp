class Solution {
public:
    long long int count = 0, k;
    
    long long int dfs(int i, vector<bool>& vis, vector<int> adj[], vector<int>& values) {
        vis[i] = true;
        long long int sum = 0;
        for(auto &j : adj[i]) {
            if(vis[j] == true)continue;
            sum += dfs(j, vis, adj, values);
        }
        sum += values[i];
        if(sum % k == 0)count++, sum = 0;
        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        this->k = k;
        vector<bool> vis(n, false);
        dfs(0, vis, adj, values);

        return count;
    }
};