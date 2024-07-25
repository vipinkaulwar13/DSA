class Solution {
public:
    void merge(vector<int>& nums, int p, int q, int r){
        int n = q-p+1;
        int m = r-q;
        vector<int>n1(n);
        vector<int>n2(m);
        
        for(int i = 0; i<n; i++){
            n1[i] = nums[p+i];
        }
        
        for(int i = 0; i<m; i++){
            n2[i] = nums[q+1+i];
        }
        int i = 0, j = 0, k = p;
        while(i<n && j<m){
            if(n1[i]<=n2[j]){
                nums[k] = n1[i];
                i++;
            }
            else{
                nums[k] = n2[j];
                j++;
            }
            k++;
            
        }
        if(i<n){
            while(i<n){
                nums[k] = n1[i];
                i++;
                k++;
            }
        }
        else{
            while(j<m){
                nums[k] = n2[j];
                j++;
                k++;
            }
        }
    }
    
    
    void mergesort(vector<int>& nums, int l, int r){
        if(l<r){
            int m = l+(r-l)/2;
        
            mergesort(nums, l, m);
            mergesort(nums, m+1, r);
            
            merge(nums, l, m, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        
        return nums;
    }
};