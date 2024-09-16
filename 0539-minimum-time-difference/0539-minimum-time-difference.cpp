class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>minuts(n);
        for(int i = 0; i<n; i++){
            int hrs = stoi(timePoints[i].substr(0,2));
            int mits = stoi(timePoints[i].substr(3));
            minuts[i] = hrs*60+mits;
        }
        sort(minuts.begin(), minuts.end());
        int mint = INT_MAX;
        for(int i = 0; i<n-1; i++){
            mint = min(mint, minuts[i+1]-minuts[i]);
        }
        mint = min(mint, 24*60+minuts.front()-minuts.back());
        
        return mint;
    }
};

