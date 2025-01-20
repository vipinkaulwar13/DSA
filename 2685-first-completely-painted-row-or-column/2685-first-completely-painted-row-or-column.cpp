class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>col(m,0);
        vector<int>row(n,0);
        unordered_set<int>st(arr.begin(), arr.end());
        unordered_map<int,pair<int,int>>tem;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(st.contains(mat[i][j])){
                    tem[mat[i][j]] = {i,j};
                }
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            int x = tem[arr[i]].first;
            int y = tem[arr[i]].second;

            col[y]++;
            row[x]++;

            if (col[y] == n || row[x] == m) {
                return i;
            }
        }

        return -1;

    }
};