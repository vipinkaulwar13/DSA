class Solution {
    vector<vector<int>> ans;
    int n;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, cur, target);
        return ans;
        
    }
    void solve(vector<int> &candidates, int i, vector<int> &cur, int target){
        if(target == 0) ans.push_back(cur);
        if(target<0 || i>=n) return;
        for(int j = i; j<n; j++){
            if(j!=i && candidates[j]==candidates[j-1]){
                continue;
            }
            cur.push_back(candidates[j]);
            solve(candidates, j+1, cur,  target-candidates[j]);
            cur.pop_back();
        }
    }
    
   
};

