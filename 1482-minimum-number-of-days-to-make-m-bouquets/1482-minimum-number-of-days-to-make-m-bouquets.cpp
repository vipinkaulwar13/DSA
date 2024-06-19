// class Solution {
// public:
//     int solve(vector<int>bloomDay, int k, int m, int x){
//         int count = 0;
//         for(int i = 0; i<bloomDay.size(); i++){
//             if(bloomDay[i]<=x) bloomDay[i] = 0;
            
//             else bloomDay[i] = bloomDay[i]-x;
//         }
//         int cnt = 0;
        
//         for(int i = 0; i<bloomDay.size(); i+=k){
//             if(bloomDay[i] == 0){
//                 cnt++;
//                 for(int j = i+1; j<k; j++){
//                     if(bloomDay[j] == 0) cnt++;
//                 }
//                 if(cnt == k){
//                     count++;
//                     cnt = 0;
//                 } 
//             }
//             if(count == m) return count;
//         }
//         return count;
        
        
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();
//         if(bloomDay.size() < m*k) return -1;
        
//         vector<int>temp = bloomDay;
        
//         sort(temp.begin(), temp.end());
//         int low = 0;
//         int high = n-1;
//         while(low<high){
//             int mid = low+(high-low)/2;
//             int res = solve(bloomDay, k, m, temp[mid]);
//             if(res<m){
//                 low = mid+1;
//             }
//             else if(res>m) high = mid-1;
            
//             else return temp[mid];
            
//         }
//         return temp[low];
//     }
// };

class Solution{
   public:
    bool canHarvest(vector<int>& bDay, int harvestDay, int m, int k) {
    int adjacent = 0;
    for (auto bloomDay : bDay) {
        adjacent = bloomDay <= harvestDay ? adjacent + 1 : 0;
        if (adjacent == k) {
            adjacent = 0;
            --m;
        }
    }
    return m <= 0;
}
int minDays(vector<int>& bDay, int m, int k) {
    if ((long long)m * k > bDay.size())
        return -1;
    auto lo = 1, hi = 1000000000;
    while (lo < hi) {
        auto mid = (hi + lo) / 2;
        if (canHarvest(bDay, mid, m, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
     
};
