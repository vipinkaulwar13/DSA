class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string ans = "";
        sort(strs.begin(), strs.end());
        int m = min(strs[0].size(), strs[n-1].size());
        for(int i = 0; i<m; i++){
            if(strs[0][i] != strs[n-1][i]){
                return ans;
            }
            ans +=strs[0][i];
        }
        return ans;
    }
};