class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count[3] = {0};
        for(int i = 0; i<n; i++){
            if(nums[i]==0) count[0]++;
            else if(nums[i] == 1) count[1]++;
            else count[2]++;
        }
        int i = 0;
        while(count[0]--) 
            nums[i++] = 0;
        while(count[1]--) 
            nums[i++] = 1;
        while(count[2]--) 
            nums[i++] = 2;
    }
};