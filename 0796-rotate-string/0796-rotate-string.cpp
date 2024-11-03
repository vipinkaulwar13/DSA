class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        
        for(int i = 0; i<n; i++){
            char temp = s[0];
            s = s.substr(1, n-1);
            s+= temp;
            if(s == goal) return true;
        }
        return false;
    }
};