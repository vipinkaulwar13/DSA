class Solution {
public:
    int countSeniors(vector<string>& details) {
        int age = 60;
        int ans = 0;
    
        for(int i = 0; i<details.size(); i++){
            int temp = (details[i][11]-48)*10+(details[i][12]-48);
            if(temp>age) ans++;
        }
        return ans;
    }
};