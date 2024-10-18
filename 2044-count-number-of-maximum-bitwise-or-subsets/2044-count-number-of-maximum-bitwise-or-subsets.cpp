class Solution {
public:
    vector<int>res;
    void solve(int i, vector<int>& nums, int curr){
        if(i == nums.size()){
            res.push_back(curr);
            return;
        }
        
        solve(i+1, nums, curr|nums[i]);
        solve(i+1, nums, curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int curr = 0;
        sort(nums.begin(), nums.end());
        solve(0, nums, curr);
        int count = 0;
        int me = *max_element(res.begin(), res.end());
        for(auto i:res){
            if(i == me) count++;
        }
        return count;
    }
};