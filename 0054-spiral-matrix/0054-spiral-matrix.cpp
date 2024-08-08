class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = 0;
        while(i<n && j<m){
            for(int x = j; x<m; x++){
                res.push_back(matrix[i][x]);
            }
            i++;
            for(int y = i; y<n; y++){
                res.push_back(matrix[y][m-1]);
            }
            m--;
            if(i<n){
                for(int x = m-1; x>=j; x--){
                    res.push_back(matrix[n-1][x]);
                }
                n--;
            }
            if(j<m){
                for(int y = n-1; y>=i; y--){
                    res.push_back(matrix[y][j]);
                }
                j++;
            }
        }
        return res;
    }
};