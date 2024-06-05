class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>counts(26, INT_MAX);
        for(auto i:words){
            vector<int>cnts(26, 0);
            for(auto j:i){
                cnts[j-'a']++;
            }
            for(int k = 0; k<26; k++){
                counts[k] = min(counts[k], cnts[k]);
            }
        }
        vector<string>ans;
        for(int i = 0; i<26; i++){
            for(int j = 0; j<counts[i]; j++){
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
        
    }
};

//initially i tried doing it with a 2d hash matrix and finding the min in each column of the matrix and pushing back the char those many times.... but there was an error... 