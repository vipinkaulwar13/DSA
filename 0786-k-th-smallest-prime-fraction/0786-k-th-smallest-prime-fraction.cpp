class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>ans(2);
        vector<float>ratio;
        
        for(int i = 0; i<n-1; i++){
            int j;
            float a = arr[i];
            for(j = i+1; j<n; j++){
                float b = arr[j];
                ratio.push_back(a/b);
                //if(ratio.size() == k+1) break;
            }
            //if(ratio.size() == k+1) break;
        }
        sort(ratio.begin(), ratio.end());
        float temp2 = ratio[k-1];
        
        for(int i = 0; i<n-1; i++){
            int j;
            float a = arr[i];
            for(j = i+1; j<n; j++){
                float b = arr[j];
                float temp = a/b;
                if(temp == temp2){
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    return ans;
                } 
            }
        }
        return ans;
    }
};