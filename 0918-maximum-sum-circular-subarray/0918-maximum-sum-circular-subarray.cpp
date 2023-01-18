class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max = 0, cur_min = 0, sum =0, max_sum = nums[0], min_sum = nums[0];
        for(auto it : nums){
            cur_max = max(cur_max, 0) + it;
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min, 0) + it;
            min_sum = min(min_sum, cur_min);
            sum+= it;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};