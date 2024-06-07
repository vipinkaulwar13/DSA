class Solution {
public:
    
    // void seperate(string& sentence, vector<string>& s, string& str, int curr){
    //     if(sentence[curr] == ' ' || curr == sentence.length()){
    //         s.push_back(str);
    //         str = "";
    //         return;
    //     }
    //     str = str + sentence[curr];
    //     seperate(sentence, s, str, curr+1);
    // }
    
    void seperate(const string& sentence, vector<string>& s, string& str) {
        istringstream iss(sentence);

        while (iss >> str) {
            s.push_back(str);
        }

    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        vector<string> s;
        string str;
        
        seperate(sentence, s, str);
        vector<int>minray(s.size(),INT_MAX);
        
        for(int i = 0; i<s.size(); i++){
            for(int j = 0; j<dictionary.size(); j++){
                int m = dictionary[j].length();
                if(s[i].substr(0, m) == dictionary[j]){
                    if(minray[i] > m){
                        s[i] = dictionary[j];
                        minray[i] = m;
                    }
                }
            }
        }
        string ans = "";
        for(int i = 0; i<s.size()-1; i++){
            ans = ans+s[i]+' ';
        }
        ans = ans + s[s.size()-1];
        return ans;
    }
};