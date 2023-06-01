class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        bool row0 = false;
        bool col0 = false;
        for(int i = 0; i<=m-1; i++){
            for(int j = 0; j<=n-1; j++){
                if(M[i][j] == 0){
                    if(i == 0) row0 = true;
                    if(j == 0) col0 = true;
                    M[i][0] = 0;
                    M[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(M[i][0] == 0 || M[0][j] == 0){
                    M[i][j] = 0;
                }
            }
        }
        
        if(row0) for(int j=0; j<n; j++) M[0][j] = 0;
        
        if(col0) for(int i=0; i<m; i++) M[i][0] = 0;
    }
};