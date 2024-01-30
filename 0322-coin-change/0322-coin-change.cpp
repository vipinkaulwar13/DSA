class Solution {
public:
    int solve(vector<int>& coins, int k){
        
        vector<int> dp(k+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i<=k; i++){
            for(int j = 0; j<coins.size(); j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                    }
                }
            }
        if(dp[k] == INT_MAX){
            return -1;
        }
        return dp[k];
    }
        
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);

    }
};