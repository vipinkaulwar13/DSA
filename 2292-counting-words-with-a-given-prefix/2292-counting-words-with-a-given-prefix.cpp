class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.size();
        int n = words.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            string temp = words[i].substr(0, m);
            if(temp == pref) count++;
        }
        return count;
    }
};