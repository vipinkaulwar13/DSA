class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>mark(n, 0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i<n; i++){
            pq.push({nums[i], i});
        }
        long long res = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(!mark[it.second]){
                mark[it.second] = 1;
                if(it.second-1>=0) mark[it.second-1] = 1;
                if(it.second+1<n) mark[it.second+1] = 1;
                res += it.first;
            }
        }
        return res;
    }
};