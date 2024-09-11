class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        for(int i = 0; i<32; i++){
            if((start&1) != (goal&1)){
                count++;
            }
            start >>= 1;
            goal >>= 1;
        }
        return count;
    }
};

