class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() == k) return true;
        if(s.size() < k) return false;

        unordered_map<char, int>mp;
        for(auto i: s){
            mp[i]++;
        }
        int cnt = 0;
        for(auto it:mp){
            if(it.second%2 != 0) cnt++;
        }
        return cnt>k ? false:true;

    }
};