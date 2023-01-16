class Solution {
public:
    bool doesintervaloverlap(vector<int>& a, vector<int>& b){
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    
    vector<int>mergeintervals(vector<int>& a, vector<int>& b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    
    void insertinterval(vector<vector<int>>& intervals, vector<int>& newinterval){
        int index = upper_bound(intervals.begin(), intervals.end(), newinterval) - intervals.begin();
        
        if(index != intervals.size()){
            intervals.insert(intervals.begin()+index, newinterval);
        }
        else{
            intervals.push_back(newinterval);
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        insertinterval(intervals, newinterval);
        
        vector<vector<int>> answer;
        for(int i = 0; i< intervals.size(); i++){
            vector<int> currinterval = {intervals[i][0],intervals[i][1]};
            
            while(i<intervals.size() && doesintervaloverlap(currinterval, intervals[i])){
                currinterval = mergeintervals(currinterval, intervals[i]);
                i++;
                
            }
            i--;
            answer.push_back(currinterval);
            
        }
        
        return answer;
    }
};