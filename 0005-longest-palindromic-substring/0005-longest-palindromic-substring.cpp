class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int msiz = 0;
        string res = "";
        int x, y;
        
       for(int i = 0; i<n; i++){
           x = i;
           y = i;
           while(x>=0 && y<n && s[x] == s[y]){
               if((y-x+1)>msiz){
                   res = s.substr(x, y-x+1);
                   msiz = y-x+1;
               }
               x--;
               y++;
           }
           x = i;
           y = i+1;
           while(x>=0 && y<n && s[x] == s[y]){
               if((y-x+1)>msiz){
                   res = s.substr(x, y-x+1);
                   msiz = y-x+1;
               }
               x--;
               y++;
           }
       }
        return res;
    }
};