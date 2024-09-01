class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        vector<vector<int>>res(m, vector<int>(n));
        
        if(s != m*n) return {};
        
        for(int i = 0; i<s; i++){
            res[i/n][i%n] = original[i];
        }
        return res;
    }
};