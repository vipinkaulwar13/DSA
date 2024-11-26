class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        
        for(int i = 0; i<edges.size(); i++){
            mp[edges[i][1]]++;
        }
        
        int count = 0;
        int ans;
        for(int i = 0; i<n; i++){
            if(mp.count(i) == 0) ans = i, count++;
        }
        return count == 1 ? ans : -1;
    }
};