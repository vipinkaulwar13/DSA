class Solution {
public:
    vector<string> ans;
    void solve(int idx, string& curr, string digits, vector<string>& pad){
        if(curr.size() == digits.length()){
            ans.push_back(curr);
            return;
        }
        string value = pad[digits[idx]-'0'];
        for(int i = 0; i<value.size(); i++){
            
            curr.push_back(value[i]);
            solve(idx + 1, curr, digits, pad);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
       string curr;
       vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, curr, digits, pad);
        return ans;
        
    }
};