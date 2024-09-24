class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(int i = 0; i<arr1.size(); i++){
            string a = to_string(arr1[i]);
            string pre = "";
            for(auto c:a){
                pre+=c;
                st.insert(pre);
            }
        }
        int ans = 0;
        for(int i = 0; i<arr2.size(); i++){
            string b = to_string(arr2[i]);
            string pre ="";
            for(auto c:b){
                pre+=c;
                if(st.count(pre))ans = max(ans, (int)pre.size());
            }
        }
        return ans;
    }
};