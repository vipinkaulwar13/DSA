class Solution {
public:
    
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> ans(n);
//         vector<int>temp;
        
        
//         temp.push_back(edges[0][0]);
        
//         for(int i = 1; i<edges.size(); i++){
//             if(edges[i][1] != edges[i-1][1]){
//                 ans[edges[i-1][1]] = temp;
//                 temp.clear();
//             }
//             else{
//                 if(ans[edges[i][0]]){
//                     temp.insert(temp.end(), ans[edges[i][0]].begin(), ans[edges[i][0]].end());
//                     sort(temp.begin(), temp.end());
//                 }
//                 temp.push_back(edges[i][0]);
//             }
//         }
//         return ans;
//     }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n), directChild(n);
    for(auto& e: edges) 
        directChild[e[0]].push_back(e[1]);
    for(int i = 0; i < n; i++)
        dfs(i, i, ans, directChild);
    return ans;
}
void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& directChild) {
    for (auto& ch: directChild[curr]) 
        if(ans[ch].size() == 0 || ans[ch].back() != x) {
            ans[ch].push_back(x);
            dfs(x, ch, ans, directChild);
        }
}
};