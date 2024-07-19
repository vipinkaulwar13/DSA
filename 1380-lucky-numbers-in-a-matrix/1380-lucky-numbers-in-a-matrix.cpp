class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int>Min(m);
        vector<int>Max(n);
        
        
        for(int i = 0; i<m; i++){
            int temp1 = INT_MAX;
            for(int j = 0; j<n; j++){
                temp1 = min(temp1, matrix[i][j]);
            }
            Min[i] = (temp1);
        }
        
        for(int i = 0; i<n; i++){
            int temp2 = INT_MIN;
            for(int j = 0; j<m; j++){
                temp2 = max(temp2, matrix[j][i]);
            }
            Max[i] = (temp2);
        }
        
        vector<int>ans;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == Max[j] && matrix[i][j] == Min[i]) {
                    ans.push_back(matrix[i][j]);
                    break;
                }
            }
        }
        return ans;
    }
};