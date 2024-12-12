class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> pq;
        
        for(int i = 0; i<n; i++){
            pq.push(gifts[i]);
        }
        
        for(int i = 0; i<k; i++){
            int temp = pq.top();
            pq.pop();
            pq.push(sqrt(temp));
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};