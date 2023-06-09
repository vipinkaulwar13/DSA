class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, 0, cur);
        return ans;
    }
    void solve(vector<int> &nums, int i, vector<int> &cur){
        ans.push_back(cur);
        for(int j = i; j<n; j++){
            if(j!=i && nums[j]==nums[j-1]){
                continue;
            }
            cur.push_back(nums[j]);
            solve(nums, j+1, cur);
            cur.pop_back();
        }
    }
    
};