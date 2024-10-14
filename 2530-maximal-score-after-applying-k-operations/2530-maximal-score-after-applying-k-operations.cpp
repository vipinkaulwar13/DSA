class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<long long>pq;
        for(int i : nums){
            pq.push(i);
        }
        while(k--){
            double tem = pq.top();
            pq.pop();
            res+= tem;  
            double tem2 = ceil(tem/3);
            pq.push(tem2);
        }
        return res;
    }
};