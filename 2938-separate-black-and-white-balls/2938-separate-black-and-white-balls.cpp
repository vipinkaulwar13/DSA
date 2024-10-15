class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long count = 0;
        long long res = 0;
        
        while(n--){
            if(s[n] == '0') count++;
            else res += count;
        }
        return res;
    }
};