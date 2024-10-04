class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int sum = accumulate(skill.begin(), skill.end(),0);
        int target = sum*2/n;
        unordered_map<long long,int>mp;
        for(int i = 0; i<n; i++){
            ++mp[skill[i]];
        }
        long long ans = 0;
        for(auto it:mp){
           
            if (!mp.count(target-it.first) || mp[target-it.first] != it.second)
                return -1;
            else
                ans += it.second * it.first * (target-it.first);
        }
        
        
        return ans/2;
    }
};


