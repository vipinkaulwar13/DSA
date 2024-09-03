class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string str = "";
       for(auto it:s){
           str += to_string(it-'a'+1);
       }
        
        while(k--){
            int temp=0;
            int i = 0;
            int n = str.size();
            while(n--){
                temp += (str[i]-'0');
                i++;
            }
            str = to_string(temp);
            ans = temp;
        }
        return ans;
    }
};