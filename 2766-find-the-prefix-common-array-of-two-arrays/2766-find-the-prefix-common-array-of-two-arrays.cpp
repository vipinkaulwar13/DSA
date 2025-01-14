class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>fre(51, 0);
        vector<int> res(A.size(), 0);
        for(int i = 0; i<A.size(); i++){
            fre[A[i]]++;
            fre[B[i]]++;
            int count = 0;
            for(int j = 0; j<51; j++){
                if(fre[j] == 2) count++;
            }
            res[i] = count;
        }
        return res;
    }
};