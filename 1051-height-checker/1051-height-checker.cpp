class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>temp = heights;
        int count = 0;
        sort(heights.begin(), heights.end());
        for(int i = 0; i<heights.size(); i++){
            if(temp[i] != heights[i]) count++;
        }
        return count;
    }
};