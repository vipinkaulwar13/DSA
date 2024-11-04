class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string res = "";
        
        char prev = word[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(word[i] == prev && count<9)count++;
            else{
                res.push_back(count+'0');
                res.push_back(prev);
                prev = word[i];
                count = 1;
            }
        }
        
        res.push_back(count+'0');
        res.push_back(prev);
        return res;
    }
};