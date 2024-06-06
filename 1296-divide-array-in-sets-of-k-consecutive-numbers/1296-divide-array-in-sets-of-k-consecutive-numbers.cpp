class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        
        unordered_map<int, int>mp;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size(); i++){
            if(mp[nums[i]] > 0){
                mp[nums[i]]--;
                for(int j = 1; j<k; j++){
                    if((mp.find(nums[i]+j) != mp.end()) && (mp[nums[i]+j] >0)) mp[nums[i]+j]--;
                    
                    else return false;   
                }
            }
        }
        return true;
    }
};