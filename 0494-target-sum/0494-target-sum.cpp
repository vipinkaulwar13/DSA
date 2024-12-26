class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> cur({{0, 1}}), next;
        for (int i = 0; i < nums.size(); i++) {
            for (auto& it : cur) {
                next[it.first+nums[i]] += cur[it.first];
                next[it.first-nums[i]] += cur[it.first];
            }
            swap(cur, next);
            next.clear();
        }
        return cur[S];
    }
};