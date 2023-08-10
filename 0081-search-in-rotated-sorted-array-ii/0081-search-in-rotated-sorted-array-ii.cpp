class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[high] == nums[mid] && nums[low] == nums[mid]){
                high--;
                low++;
            }
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>target){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else{
                if(nums[high]>= target && nums[mid]<target){
                    low = mid + 1;
                }
                else high = mid -1;
            }
        }
        return false;
    }
};