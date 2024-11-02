class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence.front() == sentence.back()){
            for(int i = 1; i<n-1; i++){
                char temp = sentence[i];
                if(temp == ' '){
                    if(sentence[i-1] != sentence[i+1]) return false;
                }
            }
        }
        else return false;
        
        return true;
    }
};