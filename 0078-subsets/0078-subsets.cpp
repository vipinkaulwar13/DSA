class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        
        int n = nums.size();
        int ss = 1<<n;
        
        for(int i = 0; i<ss; i++){
            vector<int>res;
            for(int j = 0; j<32; j++){
                if(i&(1<<j)) res.push_back(nums[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};