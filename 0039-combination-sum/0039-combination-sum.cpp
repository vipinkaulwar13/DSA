class Solution {
    vector<vector<int>> ans;
    int n;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        n = candidates.size();
        solve(candidates, 0, cur, target);
        return ans;
        
    }
    void solve(vector<int> &candidates, int i, vector<int> &cur, int target){
        if(target == 0) ans.push_back(cur);
        if(target<0 || i>=n) return;
        for(int j = i; j<n; j++){
            cur.push_back(candidates[j]);
            solve(candidates, j, cur,  target-candidates[j]);
            cur.pop_back();
        }
    }
};