class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int i = 0,j = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        j = m-1;
        while(i<n && j>=0){
            if(matrix[i][j] == target){
                found = true;
                break;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return found;
    }
};