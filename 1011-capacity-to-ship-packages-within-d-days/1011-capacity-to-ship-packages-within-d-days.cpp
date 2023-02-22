class Solution {
public:
    bool feasible(vector<int>&weights, int c, int days) {
        int daysneeded = 1, currentload = 0;
        for(auto weight : weights){
            currentload += weight;
            if(currentload>c){
                daysneeded++;
                currentload = weight;
            }
        }
        return daysneeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int totalload = 0, maxload = 0;
        for(int weight: weights){
            totalload += weight;
            maxload = max(maxload, weight);
        }
        
        int l = maxload, r = totalload;
        
        while(l<r){
            int mid = (l + r)/2;
            if(feasible(weights, mid, days)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};