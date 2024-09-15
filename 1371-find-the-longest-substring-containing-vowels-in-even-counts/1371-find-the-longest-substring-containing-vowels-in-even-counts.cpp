class Solution {
public:
    int findTheLongestSubstring(string s) {
        int curr = 0;
        int ans = 0;
        unordered_map<int,int>mp{{0,-1}};
        for(int i = 0; i<s.size(); i++){
            auto temp = string("aeiou").find(s[i]);
            if(temp!=string::npos) curr^=1<<temp;
            if(!mp.count(curr)) mp[curr] = i;
            ans = max(ans, i-mp[curr]);
        }
        return ans;
    }
};