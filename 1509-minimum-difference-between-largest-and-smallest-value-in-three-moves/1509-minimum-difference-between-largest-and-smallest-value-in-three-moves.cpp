class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        if(n<4) return 0;
        
        else{
            ans = min({nums[n-4]-nums[0], nums[n-1]-nums[3], nums[n-3]-nums[1], nums[n-2]-nums[2]});
        }
        return ans;
    }
};