class Solution {
public:
//     void solve(vector<int>& nums, vector<pair<vector<int>, int>>& res){
        
//         for(int i = 0; i<nums.size(); i++){
//             vector<int>temp;
//             int temp1 = nums[i];
//             while(temp1){
//                 temp.push_back(temp1%10);
//                 temp1/=10;
//             }
//             reverse(temp.begin(), temp.end());
//             res.push_back({temp, nums[i]});
//         }
//     }
    string largestNumber(vector<int>& nums) {
        
        // vector<pair<vector<int>, int>> res;
        // solve(nums, res);
        // sort(res.begin(), res.end(), greater<pair<vector<int>, int>>());
        // string ans = "";
        // for (auto it = res.begin(); it != res.end(); ++it) {
        //     ans += to_string(it->second);
        // }
        // return ans;
        vector<string>res;
        for(int i = 0; i<nums.size(); i++){
            res.push_back(to_string(nums[i]));
        }
        
        sort(res.begin(), res.end(), [](string& s1, string& s2){
            return s1+s2>s2+s1;
        });
        string ans = "";
        for(int i = 0; i<res.size(); i++){
            ans += res[i];
        }
        while(ans[0] == '0' && ans.length()>1){
            ans.erase(0,1);
        }
        return ans;
            
    }
};