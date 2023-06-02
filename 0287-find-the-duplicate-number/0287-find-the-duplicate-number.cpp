class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int duplicate;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto i: mp){
            if(i.second>1){
                duplicate = i.first;
            }
        }
        return duplicate;
        
    }
};