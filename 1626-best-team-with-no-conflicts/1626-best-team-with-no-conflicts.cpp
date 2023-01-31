class Solution {
public:
    int findmaxscore(vector<pair<int, int>>& agescorepair){
        int n = (int) agescorepair.size();
        int ans = 0;
        
        vector<int> dp(n);
        for(int i = 0; i<n; i++){
            dp[i] = agescorepair[i].second;
            ans = max(ans, dp[i]);
        }
        for(int i = 0; i<n; i++){
            for(int j = i-1; j>= 0; j--){
                if(agescorepair[i].second>=agescorepair[j].second){
                    dp[i] = max(dp[i], agescorepair[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> agescorepair;
        for(int i =0; i<scores.size(); i++){
            agescorepair.push_back({ages[i], scores[i]});
        }
        sort(agescorepair.begin(), agescorepair.end());
        return findmaxscore(agescorepair);
    }
};