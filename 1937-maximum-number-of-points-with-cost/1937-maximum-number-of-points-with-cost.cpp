class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long>prev(m);
        vector<long long>lft(m), rgt(m), curr(m);
        
        for(int i = 0; i<m; i++){
            prev[i] = points[0][i];
        }
        
        for(int i = 1; i<n; i++){
            lft[0] = prev[0];
            rgt[m-1] = prev[m-1];
            
            for(int j = 1; j<m; j++){
                lft[j] = max(prev[j], lft[j-1]-1);
            }
            
            for(int k = m-2; k>=0; k--){
                rgt[k] = max(prev[k], rgt[k+1]-1);
            }
            
            for(int l = 0; l<m; l++){
                curr[l] = points[i][l] + max(lft[l], rgt[l]);
            }
            prev = curr;
        }
        long long ans = 0;
        for(int i = 0; i<m; i++){
            ans = max(ans, prev[i]);
        }
        
        return ans;
        
    }
};