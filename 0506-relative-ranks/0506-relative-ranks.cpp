class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int>mp;
        for(int i = 0; i<n; i++){
            mp[score[i]] = i;
        }
        sort(score.begin(), score.end());
        int i = 1;
        while(i<=n){
            int m = mp[score[n-i]];
            if(i == 1){
                ans[m] = "Gold Medal";
            }
            else if(i == 2){
                ans[m] = "Silver Medal";
            }
            else if(i == 3){
                ans[m] = "Bronze Medal";
            }
            else{
                ans[m] = to_string(i);
            }
            i++;
        }
        return ans;
        
    }
};