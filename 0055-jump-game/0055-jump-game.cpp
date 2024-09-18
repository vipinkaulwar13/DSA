class Solution {
public:
    bool canJump(vector<int>& nums) {
        int smax = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i>smax) return false;
            
            smax = max(smax, i+nums[i]);
        }
        return true;
    }
};