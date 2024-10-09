class Solution {
public:
    int minAddToMakeValid(string s) {
//         int open = 0;
//         int close = 0;
        
//         for(auto it:s){
//             if(it == '(') open++;
//             else close++;
//         }
       stack<char>st;
        for(auto it:s){
            if(st.empty()) st.push(it);
            else if(st.top() == '(' && it == ')') st.pop();
            else st.push(it);
        }
        return st.size();
    }
};