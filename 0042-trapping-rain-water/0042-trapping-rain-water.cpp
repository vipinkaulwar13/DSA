class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lp = 0, rp = n-1;
        int lmax = height[lp], rmax = height[rp];
        int ans = 0;
        
        while(lp<=rp){
            if(lmax<=rmax){
                if(height[lp]>lmax){
                    lmax = height[lp];
                }
                else{
                    ans += (lmax-height[lp]);
                }
                lp++;
            }
            else{
                if(height[rp]>rmax){
                    rmax = height[rp];
                }
                else{
                    ans+= (rmax-height[rp]);
                }
                rp--;
            }
        }
        return ans;
    }
};