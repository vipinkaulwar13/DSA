class Solution {
public:
    bool solve(int i, vector<int>& dp, vector<int>& nums){
        if(i == nums.size()) return true;
        if(dp[i] != -1) return dp[i];
        
        if(i+1<nums.size() && nums[i] == nums[i+1]){
            if(solve(i+2, dp, nums)) return true;
            if(i+2<nums.size() && nums[i+1] == nums[i+2]){
                if(solve(i+3, dp, nums)) return true;
            }
        }
        if(i+2<nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2]-2){
            if(solve(i+3, dp, nums)) return true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(0, dp, nums);
            
    }
};