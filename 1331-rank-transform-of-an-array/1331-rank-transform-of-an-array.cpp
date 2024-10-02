class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>arr1(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i<arr.size(); i++){
            mp.emplace(arr[i], mp.size()+1);
        }
        for(int i = 0; i<arr.size(); i++){
            arr1[i] = mp[arr1[i]];
        }
        return arr1;
    }
};