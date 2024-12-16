class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        
        for(int i = 0; i<k; i++){
            int temp = pq.top().first;
            int loc = pq.top().second;
            pq.pop();
            temp *= multiplier;
            pq.push({temp, loc});
        }
        
        for(int i = 0; i<nums.size(); i++){
            int temp = pq.top().first;
            int loc = pq.top().second;
            nums[loc] = temp;
            pq.pop();
        }
        return nums;
    }
};