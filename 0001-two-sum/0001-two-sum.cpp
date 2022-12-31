class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int X) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) {
            if(m.find(X - nums[i]) != m.end()) return {i, m[X - nums[i]]};
            else m[nums[i]] = i;
        }
        return {};
    }
};