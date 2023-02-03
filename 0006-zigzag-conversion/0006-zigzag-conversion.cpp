class Solution {
public:
    string convert(string s, int numrows) {
        if(numrows == 1){
            return s;
        }
        
        string answer;
        int n = s.size();
        int charsinsection = 2 * (numrows -1);
        for(int currrow = 0; currrow < numrows; ++currrow){
            int index = currrow;
            
            while(index < n){
                answer += s[index];
                if(currrow != 0 && currrow != numrows - 1){
                int charsinbetween = charsinsection - 2*currrow;
                    
                    int secondindex = index + charsinbetween;
                
                if(secondindex < n){
                    answer += s[secondindex];
                }
            }
            index += charsinsection;
        }
            
    }
        return answer;
 }
};