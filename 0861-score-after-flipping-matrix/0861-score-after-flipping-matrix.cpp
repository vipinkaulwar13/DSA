class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j<m; j++){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }
            //else continue;
            
        }
        vector<int>a(m, 0);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[j][i] == 1){
                    a[i]++;
                }
            }
        }
        
        for(int i = 1; i<m; i++){
            if(a[i] < (n+1)/2){
                for(int j = 0; j<n; j++){
                    if(grid[j][i] == 0){
                        grid[j][i] = 1;
                    }
                    else{
                        grid[j][i] = 0;
                    }
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int row = 0;
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    row += (grid[i][j]*pow(2, m-j-1));
                }
            }
            ans += row;
        }
        return ans;
    }
};