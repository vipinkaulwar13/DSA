class Solution {
public:
    int scoreOfString(string s) {
        int sol = 0;
        for(int i = 0; i<s.size()-1; i++){
            int n = s[i];
            int m = s[i+1];
            sol += abs(n-m);
        }
        return sol;
        
    }
};