class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int msum = accumulate(rolls.begin(), rolls.end(), 0);
        int temp = (m+n)*mean-msum;
        
        if(temp<n || temp>6*n) return {};
        
        int x = temp/n;
        int y = temp%n;
        
        vector<int>res(n, x);
        
        for(int i = 0; i<y; i++){
            res[i]++;
        }
        return res;
    }
};