class Solution {
public:
vector<vector<int>>ans;
    void solve(int i, vector<int>& candidates, int target, vector<int>& temp){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i, candidates, target-candidates[i], temp);
            temp.pop_back();
        }
        solve(i+1, candidates, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};