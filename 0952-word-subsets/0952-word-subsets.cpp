class Solution {
public:

    vector<int> counter(string& word) {
        vector<int> count(26);
        for (char c : word) count[c - 'a']++;
        return count;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26), temp(26);
        vector<string> res;
        for(auto b: words2){
            temp = counter(b);
            for(int i = 0; i<26; i++){
                count[i] = max(count[i], temp[i]);
            }
        }
        int i;
        for(auto a: words1){
            temp = counter(a);
            for(i = 0; i<26; i++){
                if(temp[i]<count[i]) break;
            }
            if(i == 26) res.push_back(a);
        }

        return res;
        
    }
};