class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        int endpoint = points[0][1];
        sort(points.begin(), points.end());
        
        for(auto point : points){
         
            if(point[0]>endpoint){
                ans++;
                endpoint = point[1];
                
            }
            else{
                endpoint = min(endpoint, point[1]);
            }
        }
        return ans;
    }
};