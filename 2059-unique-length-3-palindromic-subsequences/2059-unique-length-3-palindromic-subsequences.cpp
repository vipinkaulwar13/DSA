class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26, INT_MAX);
        vector<int>last(26, 0);
        int res = 0;

        for(int i = 0; i<s.length(); i++){
            first[s[i]-'a'] = min(first[s[i]-'a'], i);
            last[s[i]-'a'] = i;
        }

        for(int i = 0; i<26; i++){
            if(first[i]<last[i]){
                res += unordered_set<char>(s.begin()+first[i]+1, s.begin()+last[i]).size();
            }
        }
        return res;

    }
};