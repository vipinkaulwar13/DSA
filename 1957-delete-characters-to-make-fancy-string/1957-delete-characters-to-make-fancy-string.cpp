class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string res = "";
        res.push_back(s[0]);
        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(s[i] == res.back()){
                cnt++;
                if(cnt<3) res+= s[i];
            }
            else{
                cnt = 1;
                res += s[i];
            }
        }
        return res;
    }
};