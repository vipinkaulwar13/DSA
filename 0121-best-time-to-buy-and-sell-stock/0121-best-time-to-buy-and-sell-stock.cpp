class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prev(n);
        prev[0] = prices[0];
        for(int i = 1; i<n; i++){
            prev[i] = min(prev[i-1], prices[i]);
        }
        int mpro = 0;
        for(int i = 0; i<n; i++){
            mpro = max(mpro, prices[i]-prev[i]);
        }
        return mpro;
    }
};