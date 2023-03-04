class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minposition = -1, maxposition = -1, leftbound = -1;
        
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i]<minK || nums[i]>maxK)
                leftbound = i;
            
            if(nums[i] == minK)
                minposition = i;
            if(nums[i] == maxK)
                maxposition = i;
            
            ans += max(0, min(maxposition, minposition) - leftbound);
        }
        return ans;
    }
};