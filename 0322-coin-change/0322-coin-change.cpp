class Solution {
public:
    
    int solve(vector<int>& coins, int k, vector<int>& dp){
        int Min = INT_MAX;
        if(k == 0){
            return 0;
        }
        if(k<0){
            return INT_MAX;
        }
        if(dp[k]!=-1){
            return dp[k];
        }
        
        for(int i = 0; i<coins.size(); i++){
            int ans = solve(coins, k-coins[i], dp);
            
            if(ans != INT_MAX){
                Min = min(Min, ans+1);
            }
            
        }
        dp[k] = Min;
        return Min;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};