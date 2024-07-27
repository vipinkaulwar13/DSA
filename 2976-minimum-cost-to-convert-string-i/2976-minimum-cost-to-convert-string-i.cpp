class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        vector<vector<long long>>res(n, vector<long long>(n, (int)(1e9)));
        
        for(int i = 0; i<original.size(); i++){
            res[original[i]-'a'][changed[i]-'a'] = min(res[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }
        
        for(int v = 0; v<n; v++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    res[i][j] = min(res[i][j], res[i][v]+res[v][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i<source.size(); i++){
            if(source[i]!= target[i]){
                if(res[source[i]-'a'][target[i]-'a'] >= (int)(1e9)) return -1;
                ans+= res[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};