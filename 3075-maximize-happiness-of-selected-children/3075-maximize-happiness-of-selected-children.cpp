class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long ans = 0;
        int count = 0;
        
        for(int i = n-1; i>=n-k; i--){
            if((happiness[i]-count)>0){
                ans = ans + (happiness[i] -count);
                count++;
            }
            else break;
            
        }
        return ans;
        
    }
};