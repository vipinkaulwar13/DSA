class Solution {
public:
    
    void solve(vector<int>& nums, vector<int>& ans){
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum+=nums[j];
                ans.push_back(sum);
            }
        }
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        solve(nums, ans);
        sort(ans.begin(), ans.end());
        int res = 0;
        const int mod = 1e9+7;
        for(int i = left-1; i<right; i++){
            res += ans[i];
            res%=mod;
        }
        return res;
    }
};