class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int count = 0;
        
//         for(int i = 0; i<nums.size(); i++){
//             if(mp.find(nums[i]) != mp.end()){
//                 for(int j = nums[i]+1; j<pow(10, 5); j++){
//                     if(mp.find(j) == mp.end()){
//                         count += (j-nums[i]);
//                         nums[i] = j;
//                         break;
//                     }
//                 }
//             }
//             mp[nums[i]]++;
            
//         }

//         return count;
       for(int i = 1; i<n; i++){
           if(nums[i]<=nums[i-1]){
               count += nums[i-1]-nums[i]+1;
               nums[i] = nums[i-1]+1;
           }
       }
        return count;
    }
};