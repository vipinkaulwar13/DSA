class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start_pt = 0, cur_gas = 0, total_gas = 0, total_cost = 0;
        
        for(int i = 0; i<n ; i++){
            
            total_gas += gas[i];
            total_cost += cost[i];
            
            cur_gas += gas[i] - cost[i];
            
            if(cur_gas < 0){
                start_pt = i+1;
                
                cur_gas = 0;
            }
            
        }
        return total_cost>total_gas ? -1 : start_pt;
    }
};