class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int i = 0;
        stack<char>st;
        
        while(i<n){
            if(st.empty()) st.push(s[i]);
            else if((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};