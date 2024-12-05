class Solution {
public:
//     bool canChange(string start, string target) {
//         int n = start.size();
        
//         int i = 0, j = 0;
//         while(i<n && j<n){
//             if(start[i] == target[j]){
//                 if(start[i] == 'L' && target[j] == 'L' && i<j) return false;
//                 else if(start[i] == 'R' && target[j] == 'R' && i>j) return false;
//                 i++, j++;
//             }
//             else{
//                 if(start[i] == '_') i++;
//                 else if(target[j] == '_') j++;
//             }
//         }
//        return i == n && j == n;
//     }
    
    bool canChange(string start, string target) {
        int lcount = 0, rcount = 0;
        for(int i  = 0; i < start.size(); ++i){
            if(start[i] == 'L') { lcount++; if(rcount != 0) return false; }
            if(target[i] == 'L'){ lcount--; }
            if(start[i] == 'R') { rcount++; }
            if(target[i] == 'R'){ rcount--; if(lcount != 0) return false; }
            if(lcount > 0 || rcount < 0) return false;
        }
        if(lcount != 0 || rcount != 0) return false;
        return true;
    }
};