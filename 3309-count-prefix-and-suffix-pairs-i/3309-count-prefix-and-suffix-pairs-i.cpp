class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;

        for(int i = 0; i<n; i++){
            int t1 = words[i].size();
            for(int j = i+1; j<n; j++){
                int t2 = words[j].size();
                if(words[i] == words[j]) res++;
                if(t1<t2){
                    string temp1 = words[j].substr(0, t1);
                    string temp2 = words[j].substr(t2-t1, t1);
                    cout<<temp1<<" "<<temp2<<endl;
                    if(words[i] == temp1 && words[i] == temp2) res++;
                }
                
            }
        }
        return res;
    }
};