class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rn{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = rn[s.back()];
        int n = s.size();
        for(int i= n-2; i>=0; i--){
            if(rn[s[i]]<rn[s[i+1]])
                ans -= rn[s[i]];
            else
                ans += rn[s[i]]; 
        }return ans;
    }
};