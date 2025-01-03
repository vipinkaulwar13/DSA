class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>temp(n+1, 0);

        for(int i = 0; i<n; i++){
            temp[i+1] = nums[i] + temp[i];
        }
        int count = 0;
        for(int i = 1; i<temp.size()-1; i++){
            if(temp[i]>= temp[n]-temp[i]) count++;
        }
        return count;
    }
};