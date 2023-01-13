class Solution {
public:
    
    int dfs(int currentnode, vector<vector<int>>& children, string& s, int& longestpath){
        int longestchain = 0, secondlongestchain = 0;
        for(auto child: children[currentnode]){
            int longestchainstartingfromchild = dfs(child, children, s, longestpath);
            if(s[currentnode] == s[child]){
                continue;
            }
            if(longestchainstartingfromchild > longestchain){
                secondlongestchain = longestchain;
                longestchain = longestchainstartingfromchild;
            }
            else if (longestchainstartingfromchild>secondlongestchain){
                secondlongestchain = longestchainstartingfromchild;
            }
        }
        longestpath = max(longestpath, longestchain+secondlongestchain+1);
        return longestchain +1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>children(n);
        
        for(int i = 1; i<n; i++){
            children[parent[i]].push_back(i);   
            
        }
        int longestpath = 1;
        dfs(0, children, s, longestpath);
        
        return longestpath;
    }
};