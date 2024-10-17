class Solution {
public:
    // int maximumSwap(int num) {
    //     vector<pair<char,int>>pos;
    //     string s = to_string(num);
    //     for(int i = 0; i<s.size(); i++){
    //         pos.push_back({s[i], i});
    //     }
    //     auto comp = [](auto a, auto b){
    //         return a.first == b.first ? a.second<b.second:a.first>b.first;
    //     };
    //     sort(pos.begin(), pos.end(), greater<pair<char,int>>());
    //     for(int i = 0; i<s.size(); i++){
    //         if(s[i] != pos[i].first && s[i]<pos[i].first){
    //             int j = pos[i].second;
    //             swap(s[i], s[j]);
    //             break;
    //         }
    //     }
    //     return stoi(s);
    // }
    
    int maximumSwap(int num) {
    string numString = to_string(num);
    int n = numString.length();
    vector<int> dpPosition(n, -1);
        
    int curMaxPos = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (numString[i] > numString[curMaxPos]) {
            curMaxPos = i;
        }
        dpPosition[i] = curMaxPos;
    }
        
    for (int i = 0; i < n; i++) {
        if(numString[dpPosition[i]] != numString[i]) {
            swap(numString[i], numString[dpPosition[i]]);
            break;
        }
    }
        
    return stoi(numString);
}
};