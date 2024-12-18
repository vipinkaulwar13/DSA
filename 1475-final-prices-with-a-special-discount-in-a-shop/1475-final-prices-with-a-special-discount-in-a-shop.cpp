class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans(n, 0);
        
        for(int i = 0; i<n; i++){
            int j;
            for(j = i+1; j<n; j++){
                if(prices[i]>=prices[j]){
                    ans[i] = prices[i]-prices[j];
                    break;
                }
            }
            if(j == n) ans[i] = prices[i];
        }
        return ans;
    }
};