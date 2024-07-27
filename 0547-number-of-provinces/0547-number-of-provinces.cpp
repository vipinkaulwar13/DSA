class Solution {
public:
    
    void dfs(int i, unordered_map<int, list<int>>& mp, unordered_map<int, bool>& visited){
        visited[i] = true;
        
        for(auto it:mp[i]){
            if(!visited[it]){
                dfs(it, mp, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>>mp;
        int n = isConnected.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        
        unordered_map<int, bool>visited;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, mp, visited);
            }
        }
        return count;
    }
};