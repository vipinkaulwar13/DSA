class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maax = INT_MIN;
        int loc = 0;
        int x = 0;
        for(int i = 0; i<=customers.size()-minutes; i++){
            int res = 0, res2 = 0;
            for(int j = i; j<i+minutes; j++){
                if(grumpy[j] == 0){
                    res += customers[j];
                }
                res2 += customers[j];
            }
            if(maax<(res2-res)){
                loc = i;
                maax = res2-res;
                x = res2;
            }
        }
        int ans = 0;
        for(int i = 0; i<loc; i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
        }
        ans += x;
        if(loc+minutes<customers.size()){
            for(int i = loc+minutes; i<customers.size(); i++){
                if(grumpy[i] == 0){
                    ans += customers[i];
                }
            }
        }
        
        return ans;
    }
};