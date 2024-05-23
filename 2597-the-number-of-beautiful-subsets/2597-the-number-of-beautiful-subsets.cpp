class Solution {
public:
    vector<vector<int>>ans;
    bool isBeautiful(vector<int>& curr, int k){
        int n = curr.size();
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<n; j++){
                if(abs(curr[i]-curr[j]) == k) return false;
            }
        }
        return true;
            
    }
    void solve(vector<int>& nums, int i, vector<int>& curr, int k){
        if(i == nums.size()){
            if(isBeautiful(curr, k)) ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[i]);
        solve(nums, i+1, curr, k);
        curr.pop_back();
        solve(nums, i+1, curr, k);
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>curr;
        solve(nums, 0, curr, k);
        
        return ans.size()-1;
    }
};