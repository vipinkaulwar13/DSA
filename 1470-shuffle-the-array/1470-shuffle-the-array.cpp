class Solution {
public:
    
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
            ans.push_back(nums[0]);
        for(int i = 1, j = n; i<n, j<2*n-1; i++, j++){
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
        }
        ans.push_back(nums[2*n-1]);
        return ans;
    }
};