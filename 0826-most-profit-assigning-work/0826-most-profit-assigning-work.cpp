class Solution {
public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         vector<pair<int, int>>dp;
//         int ans = 0;
//         for(int i = 0; i<profit.size(); i++){
//             dp.push_back({profit[i], difficulty[i]});
//         }
        
//         sort(dp.begin(), dp.end());
//         sort(worker.begin(), worker.end());
        
//         int j = dp.size()-1;
//         int i = worker.size()-1;
//         while(i>0 && j>0){
//             if(worker[i]>=dp[j].second){
//                 ans+= dp[j].first;
//                 i--;
//             }
//             else{
//                 j--;
//             }
//         }
//         return ans;
//         //theory 1- use upper bound and lower bound to find workers who can work on jobs which have a difficulty <= the capacity of a worker.
//         // insert the diff and pro vectors in a vector pair and sort them
        
//     }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int N = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < N; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int & ability : worker) {
            while (i < N && ability >= jobs[i].first)
                best = max(jobs[i++].second, best);
            res += best;
        }
        return res;
    }
};