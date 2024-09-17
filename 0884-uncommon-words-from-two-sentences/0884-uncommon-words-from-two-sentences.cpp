class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>m1;
        unordered_map<string, int>m2;
        vector<string> res;
        
        istringstream s(s1);
        string temp;
        while(s>>temp){
            m1[temp]++;
        }
        istringstream t(s2);
        while(t>>temp){
            m2[temp]++;
        }
        
        for(auto it:m1){
            if((m2.find(it.first) == m2.end()) && it.second==1){
                res.push_back(it.first);
            }
        }
        
        for(auto it:m2){
            if((m1.find(it.first) == m1.end()) && it.second==1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};