class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int l = 0, ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i<len; i++){
            if(mp.find(s[i]) != mp.end()) l = max(l, mp[s[i]]+1);
            ans = max(ans, i-l+1);
            mp[s[i]] = i;
        }
        return ans;
    }
};