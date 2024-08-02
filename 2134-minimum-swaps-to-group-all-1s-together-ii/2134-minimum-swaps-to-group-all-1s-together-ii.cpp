class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1) count++;
        }
        nums.insert(nums.end(), nums.begin(), nums.end());
        int cnt = 0;
        int mcnt = INT_MAX;
        for(int i = 0; i<count; i++){
            if(nums[i] == 0) cnt++;
        }
        mcnt = min(mcnt, cnt);
        
        for(int i = count; i<nums.size(); i++){
            if(nums[i-count] == 0 && nums[i] ==1) cnt--;
            
            else if(nums[i-count] == 1 && nums[i] == 0) cnt++;
            
            else if(nums[i-count] == 1 && nums[i] == 1) continue;
            
            else continue;
            
            mcnt = min(mcnt, cnt);
        }
        
        return mcnt;
            
    }
};