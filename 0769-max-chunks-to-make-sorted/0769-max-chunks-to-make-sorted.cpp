class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int res = 0, ans = 0, sum = 0;
        for(int i = 0; i<n; i++){
            res += i;
            sum += arr[i];
            if(res == sum) ans++;
        }
        return ans;
    }
};