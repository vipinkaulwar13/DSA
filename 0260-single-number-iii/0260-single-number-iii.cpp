class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> sol;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i<n-1; i++){
            if(nums[i+1] == nums[i]) continue;
            
            else{
                if(nums[i] == nums[i-1]) continue;
                
                else{
                    sol.push_back(nums[i]);
                }
            }
        } 
        if(nums[0] != nums[1]) sol.push_back(nums[0]);
        if(nums[n-1] != nums[n-2]) sol.push_back(nums[n-1]);
        sort(sol.begin(), sol.end());
        
        return sol;
    }
};