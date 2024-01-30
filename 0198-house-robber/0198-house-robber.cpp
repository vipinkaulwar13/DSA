class Solution {
public:
    
    int solve(vector<int>& nums, int x, vector<int>& dp){
        if(x<0){
            return 0;
        }
        if(x == 0){
            return nums[x];
        }
        if(dp[x] != -1){
            return dp[x];
        }
        
        int include = solve(nums, x-2, dp) + nums[x];
        int exclude = solve(nums, x-1, dp);
        
        dp[x] = max(include, exclude);
        
        return dp[x];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = solve(nums, n-1, dp);
        return ans;
    }
};