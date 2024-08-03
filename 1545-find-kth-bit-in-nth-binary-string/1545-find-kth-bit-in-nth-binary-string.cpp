class Solution {
public:
    
    string invert(string x){
        for(int i = 0; i<x.size(); i++){
            if(x[i] == '0') x[i] = '1';
            else x[i] = '0';
        }
        return x;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        
        string prev = s;
        string curr = "";
        for(int i = 2; i<=n; i++){
            string temp = invert(prev);
            reverse(temp.begin(), temp.end());
            curr = prev+"1"+ temp;
            prev = curr;
        }
        return prev[k-1];
    }
};