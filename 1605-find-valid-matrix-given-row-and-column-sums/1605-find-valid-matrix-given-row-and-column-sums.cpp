class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        vector<vector<int>>res(rowSum.size(), vector<int>(colSum.size()));
        
        
        for(int i = 0; i<rowSum.size(); i++){
            for(int j = 0; j<colSum.size(); j++){
                res[i][j] = min(rowSum[i], colSum[j]);
                if(rowSum[i]>=colSum[j]){
                    rowSum[i] -= colSum[j];
                    colSum[j] = 0;
                }
                else{
                    colSum[j] -= rowSum[i];
                    rowSum[i] = 0;
                }
            }
        }
        return res;
    }
};