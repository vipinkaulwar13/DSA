class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre(n, 0);
        vector<int>suf(n, 0);
        int lmax = 0;
        int rmax = 0;
        int res = 0;
        
        for(int i = 0; i<height.size(); i++){
            if(lmax<height[i]){
                lmax = height[i];
            }
            pre[i] = max(lmax, height[i]);
            if(rmax<height[n-i-1]){
                rmax = height[n-i-1];
            }
            suf[n-i-1] = max(rmax, height[n-i-1]);
        }
        
        for(int i = 0; i<n; i++){
            res += (min(pre[i], suf[i])-height[i]);
        }
        return res;
    }
};