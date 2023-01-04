class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        
        for(int vlaue: tasks){
            freq[vlaue]++;
        }
        int minrounds = 0;
        for(auto it :freq){
            
            if(it.second == 1){
                return -1;
            }
            if(it.second%3 == 0){
                minrounds += it.second/3;
            }
            else{
                minrounds += it.second/3 + 1;
            }
                
        }
        return minrounds;
    }
    
};