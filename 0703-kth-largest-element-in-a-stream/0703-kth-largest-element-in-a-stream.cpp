class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto i:nums){
            q.push(i);
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>size)q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */