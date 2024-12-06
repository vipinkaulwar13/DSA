class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        for(auto i: banned){
            st.insert(i);
        }
        int sum = 0;
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(!st.contains(i)) sum+= i, count++;
            if(sum>maxSum){
                count--;
                break;
            }
        }
        
        
        return count;
    }
};