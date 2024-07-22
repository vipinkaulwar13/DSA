class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>res;
        
        for(int i = 0; i<heights.size(); i++){
            res.push_back({heights[i], names[i]});
        }
        
        sort(res.begin(), res.end());
        
        vector<string> temp;
        
        for(int i = 0; i<heights.size(); i++){
            temp.push_back(res[heights.size()-1-i].second);
        }
        return temp;
    }
};