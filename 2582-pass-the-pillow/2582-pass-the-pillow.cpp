class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 0;
        if(n<=time){
            int temp = time/(n-1);
            int temp1 = time%(n-1);
            if(temp%2 == 0){
                ans = 1+temp1;
            }
            else ans = n-temp1;
        }
        else{
            int diff = n-time;
            ans = time+1;
        }
        return ans;
    }
};