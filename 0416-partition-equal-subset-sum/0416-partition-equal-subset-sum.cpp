class Solution {
public:
    bool solve(int i, int tar, vector<int>& nums, vector<vector<int>>& dp){
        if(i == 0){
            return nums[0] == tar;
        }
        if(tar == 0) return true;
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        bool ntake = solve(i-1, tar, nums, dp);
        bool take = false;
        if(nums[i]<=tar){
            take = solve(i-1, tar-nums[i], nums, dp);
        }
        return dp[i][tar] = ntake || take;
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        vector<vector<int>>dp(nums.size(), vector<int>((sum/2)+1, -1));
        return solve(n-1, sum/2, nums, dp);
        
    }
};