class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{'){
                S.push(c);
            }
            else {
                if (S.empty()) {
                    return false;
                }
                if (c == ')' && S.top() == '(') {
                    S.pop();
                } else if (c == '}' && S.top() == '{') {
                    S.pop();
                } else if (c == ']' && S.top() == '[') {
                    S.pop();
                } else {
                    return false;
                }
            }
        }
        return S.empty();
    }
};