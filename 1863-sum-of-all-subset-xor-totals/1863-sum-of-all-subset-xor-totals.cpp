class Solution {
public:
    int res = 0;
    void solve(vector<int>& nums, int m, vector<int>& curr){
        if(m == nums.size()){
            int temp = 0;
            for(auto &i:curr){
                temp ^= i;
            }
            res += temp;
            return;
        }
        curr.push_back(nums[m]);
        solve(nums, m+1, curr);
        
        curr.pop_back();
        solve(nums, m+1, curr);
        
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<int>curr;
        solve(nums, 0, curr);
        return res;
    }
};