class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }
        for(int i = 0; i<arr.size(); i++){
            int temp = arr[i] *2;
            if(mp.count(temp)){
                if(mp[temp] != i) return true;
            }
        }
        return false;
    }
};