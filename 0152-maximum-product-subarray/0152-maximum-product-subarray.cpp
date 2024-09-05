class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        int mpro = 0;
        for(int i = 0; i<n; i++){
            int curr = 1;
            for(int j = i; j<n; j++){
                curr *= nums[j];
                mpro = max(mpro, curr);
            }
        }
        return mpro;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        return solve(nums);
    }
};