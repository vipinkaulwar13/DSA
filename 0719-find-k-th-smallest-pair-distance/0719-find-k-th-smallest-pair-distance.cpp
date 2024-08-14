// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int high = nums[n-1]-nums[0];
//         int low = INT_MIN;
//         for(int i = 1; i<n; i++){
//             int diff = nums[i]+nums[i-1];
//             low = min(diff, low);
//         }
//         int mid, ans = 0;
//         while(high>low){
//             mid = low+(high-low)/2;
//             if(k>(mid-low)) low = mid+1;
//             else if(k<(mid-low)) high = mid-1;
//             else{
                
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool check(int mid,vector<int> &nums,int k){
      int total=0;
      int j=0,n=nums.size();
      for(int i=0;i<n;i++){
        while(j<n && nums[j]-nums[i]<=mid)j++;
        j--;
        total+=(j-i);
      }
      return total>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int l=0,r = nums[n-1]-nums[0];
      while(l<r){
        int mid = (l+r)/2;
        if(check(mid,nums,k)){
          r=mid;
        }
        else{
          l=mid+1;
        }
      }
      return l;
    }
};