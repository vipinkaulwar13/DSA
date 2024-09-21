class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>s(n+1);
        
        for(int i = 1; i<=n; i++){
            s[i] = to_string(i);
        }
        sort(s.begin(), s.end());
        vector<int>res(n);
        for(int i = 0; i<n; i++){
            res[i] = stoi(s[i+1]);
        }
        return res;
        
    }
};