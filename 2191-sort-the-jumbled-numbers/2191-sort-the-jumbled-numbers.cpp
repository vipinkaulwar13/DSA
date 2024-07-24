class Solution {
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int>mp;
        
        for(int i = 0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            long long ans = 0;
            for(auto it: s){
                ans *= 10;
                ans+=mapping[it-'0'];
            }
            mp[nums[i]] = ans;
        }
        auto cmp = [&](auto a, auto b){
            return mp[a]<mp[b];
        };
        sort(nums.begin(), nums.end(), cmp);
        
        return nums;
    }
};