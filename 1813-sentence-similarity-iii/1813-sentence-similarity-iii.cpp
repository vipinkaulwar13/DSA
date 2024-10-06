class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string>x,y;
        string temp = "";
        for(char t:sentence1){
            if(t == ' '){
                x.push_back(temp);
                temp = "";
            }
            else temp+=t;
        }
        x.push_back(temp);
        temp = "";
        for(char t:sentence2){
            if(t == ' '){
                y.push_back(temp);
                temp = "";
            }
            else temp+=t;
        }
        y.push_back(temp);
        
        while(x.size() && y.size() &&  x.front() == y.front()){
            x.pop_front();
            y.pop_front();
        }
        while(x.size() && y.size() &&  x.back() == y.back()){
            x.pop_back();
            y.pop_back();
        }
        if(x.size() == 0||y.size() == 0) return true;
        return false;
    }
    
};