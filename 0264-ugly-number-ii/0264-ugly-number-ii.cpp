class Solution {
public:
//     int nthUglyNumber(int n) {
//         set<int>temp;
//         priority_queue <int, vector<int>, greater<int>> q;
        
//         q.push(1);
        
//         while(temp.size()<n){
//             int x = q.top();
//             q.pop();
//             temp.insert(x);
            
//             q.push(x*2);
//             q.push(x*3);
//             q.push(x*5);
//         }
        
//         return *temp.rbegin();
        
//     }
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int x=0, y=0, z=0;
        for(int i=1; i<n; i++){
            dp[i] = min({dp[x]*2, dp[y]*3, dp[z]*5});
            if(dp[i] == 2*dp[x]) x++;
            if(dp[i] == 3*dp[y]) y++;
            if(dp[i] == 5*dp[z]) z++;
        }
        return dp[n-1];
    }
    
};