class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        vector<int>temp;
        
        for(int i = 0; i<arr1.size(); i++){
            mp[arr1[i]]++;
        }
        
        arr1.clear();
        for(int i = 0; i<arr2.size(); i++){
            if(mp.find(arr2[i]) != mp.end()){
                for(int j = 0; j<mp[arr2[i]]; j++){
                    arr1.push_back(arr2[i]);
                }
                mp.erase(arr2[i]);
            }
            
        }
        for(auto it:mp){
            for(int i = 0; i<it.second; i++){
                arr1.push_back(it.first);
            }
        }
        return arr1;
    }
};