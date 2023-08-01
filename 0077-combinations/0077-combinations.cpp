class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> set;
        solve(n, 1, k, set);
        return ans;
        
    }
    void solve(int n, int l, int k, vector<int> &set){
        if(set.size() == k){
            ans.push_back(set);
            return;
            
        }
        for(int i = l; i<=n; i++){
            set.push_back(i);
            solve(n, i+1, k, set);
            set.pop_back();
        }
        
    }
};
