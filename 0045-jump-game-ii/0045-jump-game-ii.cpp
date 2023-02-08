class Solution {
public:
    int jump(vector<int>& nums) {
       int ans = 0, n = int(nums.size());
        int curend = 0, curfar = 0;
        
        for(int i = 0; i<n-1; ++i){
            curfar = max(curfar, i+nums[i]);
            
            if(i == curend){
                ans++;
                curend = curfar;
            }
        }
        return ans;
    }
};