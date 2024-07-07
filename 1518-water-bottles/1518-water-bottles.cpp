class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int currf = numBottles;
        int curre = 0;
        int res = 0;
        
        while(currf != 0){
            res+=currf;
            curre += currf;
            currf = curre/numExchange;
            curre = curre%numExchange;
        }
        return res;
        
    }
};