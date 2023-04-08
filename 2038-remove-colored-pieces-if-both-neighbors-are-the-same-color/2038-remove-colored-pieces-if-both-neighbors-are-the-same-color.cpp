class Solution {
public:
    bool winnerOfGame(string colors) {
        string str=colors;
    vector<int> l_black;
    vector<int> l_white;
    char pres=str[0];
    int w_counter=0;
    int b_counter=0;
    if(pres=='A'){
        w_counter++;
    }
    else{
        b_counter++;
    }
    for(int i=1;i<str.length();i++){
        char k=str[i];
        if(b_counter==0 && k=='A'){
            w_counter++;
        }
        else if(w_counter==0 && k=='B'){
            b_counter++;
        }
        else if(w_counter!=0 && k=='B'){
            l_white.push_back(max(0,w_counter-2));
            w_counter=0;b_counter++;
        }
        else{
            l_black.push_back(max(0,b_counter-2));
            b_counter=0;w_counter++;
        }
    }
    if(w_counter!=0){
        l_white.push_back(max(0,w_counter-2));
    }
    if(b_counter!=0){
        l_black.push_back(max(0,b_counter-2));
    }
    int w_score=0;
    int b_score=0;
    for(int i=0;i<l_black.size();i++){
        b_score+=l_black[i];
    }
    for(int i=0;i<l_white.size();i++){
        w_score+=l_white[i];
    }
    if(w_score>b_score){
        return true;
    }
    else{
        return false;
    }
    }
};