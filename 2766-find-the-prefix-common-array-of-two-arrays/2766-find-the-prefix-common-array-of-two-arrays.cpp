class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>s1,s2;
        int n = A.size();
        vector<int> res(n+1, 0);
        for(int i = 0; i<n; i++){
            if(A[i] == B[i]) res[i+1] = res[i]+1;
            else{
                if(s1.contains(B[i]) && s2.contains(A[i])) res[i+1]+=2;
                else if(!s1.contains(B[i]) && !s2.contains(A[i])){
                    s1.insert(A[i]);
                    s2.insert(B[i]);
                }
                else{
                    if(!s1.contains(B[i])) s2.insert(B[i]);
                    else s1.insert(A[i]);
                    res[i+1]++;
                }
                res[i+1] += res[i];
            }
        }
        vector<int>ans(res.begin()+1, res.end());
        return ans;
    }
};