
class Solution {
    vector<vector<string>> ans;
     vector<string> cur;
    int n;
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        n = s.size();
        solve(s, 0, cur);
        return ans;
        
    }
    void solve(string &s, int i, vector<string> &cur){
        if(i == n){
            ans.push_back(cur);
        }
        else{
            for(int j = i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    cur.push_back(s.substr(i,j-i+1));
                    solve(s, j+1, cur);
                    cur.pop_back();
                }
            
            }
        }
        
    }
    bool isPalindrome(int start, int end, string &s){
        while(start<end){
            if(s[start++]!= s[end--]){
                return false;
            }
        }
        return true;
    }
};
