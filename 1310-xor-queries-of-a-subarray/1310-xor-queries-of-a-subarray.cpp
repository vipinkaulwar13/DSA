class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pre(arr.size());
        vector<int>ans;
        pre[0] = arr[0];
        for(int i = 1; i<arr.size(); i++){
            pre[i] = arr[i]^pre[i-1];
        }
        for(int i = 0; i<queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(x == 0) ans.push_back(pre[y]);
            else{
                ans.push_back(pre[x-1]^pre[y]);
            }
        }
        return ans;
    }
};