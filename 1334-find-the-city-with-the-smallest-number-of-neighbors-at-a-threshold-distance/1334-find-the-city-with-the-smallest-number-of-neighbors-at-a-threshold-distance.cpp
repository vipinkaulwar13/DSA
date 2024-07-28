class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>res(n, vector<int>(n, 10001));
        int small = n, ans = 0;
        for(int i = 0; i<edges.size(); i++){
            res[edges[i][0]][edges[i][1]] = edges[i][2];
            res[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i = 0; i<n; i++){
            res[i][i] = 0;
        }
        for(int v = 0; v<n; v++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    res[i][j] = min(res[i][j], res[i][v]+res[v][j]);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(res[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=small){
                small = count;
                ans = i;
            }
        }
        
        return ans;
    }
};