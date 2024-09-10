class Solution {
public:
    int solve(int idx, int target, vector<vector<int>>& dp, vector<int>& coins){
        if(idx == 0){
            if(target%coins[0] == 0)return target/coins[0];
            else return 1e9;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int take = INT_MAX;
        int ntake = solve(idx-1, target, dp, coins);
        if(coins[idx]<=target){
            take = 1+solve(idx, target-coins[idx], dp, coins);
        }
        return dp[idx][target] = min(ntake, take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, dp, coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};