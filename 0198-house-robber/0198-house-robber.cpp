class Solution {
public:
    int solve(vector<int>& nums, int x){
        
        if(x == 1){
            return nums[0];
        }
        
        int prev1 = 0;
        int prev2 = nums[0];
        
        for(int i = 1; i<x; i++){
            int include = prev1 + nums[i];
            int exclude = prev2;
            
            int ans = max(include, exclude);
            prev1 = prev2;
            prev2 = ans;
            
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n);
    }
};