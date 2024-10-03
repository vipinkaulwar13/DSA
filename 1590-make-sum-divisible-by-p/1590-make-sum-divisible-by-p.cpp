class Solution {
public:
   int minSubarray(vector<int>& nums, int p) {
    int mod = 0, r_mod = 0, min_w = nums.size();
    for (auto n : nums)
        mod = (mod + n) % p;
    if (mod == 0)
        return 0;
    unordered_map<int, int> pos = {{0, -1}};
    for (int i = 0; i < nums.size(); ++i) {
        r_mod = (r_mod + nums[i]) % p;
        int comp = (p - mod + r_mod) % p;
        if (pos.count(comp))
            min_w = min(min_w, i - pos[comp]);
        pos[r_mod] = i;
    }
    return min_w >= nums.size() ? -1 : min_w;
}
};