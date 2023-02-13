class Solution {
public:
    int ans = 0;
    int countOdds(int low, int high) {
        if(!(low&1)){
            low++;
        }
        return low>high ? 0 : (high -low)/2 +1;
    }
};