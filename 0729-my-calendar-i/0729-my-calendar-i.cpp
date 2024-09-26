class MyCalendar {
    vector<pair<int,int>>res;
public:
    
    bool book(int start, int end) {
        for(auto it:res){
            if(max(it.first, start) <min(it.second, end)) return false;
        }
        res.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */