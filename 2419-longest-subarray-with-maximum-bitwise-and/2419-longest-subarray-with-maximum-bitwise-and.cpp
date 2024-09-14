class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        int ans = 0, len = 0;
        
        int x = * max_element(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == x) ans = max(ans, ++len);
            else len = 0;
            
        }
        return ans;
    }
};