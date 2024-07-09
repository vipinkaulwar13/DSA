class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int>res(customers.size());
        double ans = 0;
        res[0] = customers[0][0]+customers[0][1];
        for(int i = 1; i<customers.size(); i++){
            if(customers[i][0]>res[i-1]){
                res[i] = customers[i][0]+customers[i][1];
            }
            else{
                res[i] = res[i-1] + customers[i][1];
            }
            
        }
        
        for(int i = 0; i<res.size(); i++){
            ans += (res[i]-customers[i][0]);
        }
        ans = ans/customers.size();
        return ans;
    }
};