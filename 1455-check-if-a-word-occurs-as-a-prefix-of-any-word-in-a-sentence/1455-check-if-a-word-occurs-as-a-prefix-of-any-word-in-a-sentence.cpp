class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string temp = "";
        int count = 0;
        int siz = searchWord.size();
        while(ss>>temp){
            count++;
            if(temp.size()>=siz){
                string res = temp.substr(0, siz);
                if(res == searchWord){
                     return count;
                }
            }
        }
        return -1;
    }
};