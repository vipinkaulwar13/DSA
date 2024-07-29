class Solution {
public:
//     void solve(int i, vector<int>& rating, vector<int>& curr, int& count){
//         if(i == rating.size()){
//             if(curr.size() == 3){
//                 if(((curr[0]<curr[1]) && (curr[1]<curr[2])) || ((curr[0]>curr[1]) && (curr[1]>curr[2]))) count++;   
//             }
//             return;
//         }
//         curr.push_back(rating[i]);
//         solve(i+1, rating, curr, count);
        
//         curr.pop_back();
//         solve(i+1, rating, curr, count);
//     }
//     int numTeams(vector<int>& rating) {
//         int count = 0;
//         vector<int>curr;
//         solve(0, rating, curr, count);
        
//         return count;
//     }
    int numTeams(vector<int>& rating) {
    int res = 0;
    for (auto i = 1; i < rating.size() - 1; ++i) {
        int less[2] = {}, greater[2] = {};
        for (auto j = 0; j < rating.size(); ++j) {
            if (rating[i] < rating[j])
                ++less[j > i];
            if (rating[i] > rating[j])
                ++greater[j > i];
        }
        res += less[0] * greater[1] + greater[0] * less[1];
    }
    return res;
}
};