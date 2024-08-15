class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fcnt = 0, tcnt = 0, wcnt = 0;
        if(bills[0] != 5) return false;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5) fcnt++;
            
            else if(bills[i] == 10){
                if(fcnt){
                    fcnt--;
                    tcnt++;
                }
                else return false;
            }
            
            else{
                if(fcnt && tcnt){
                    fcnt--;
                    tcnt--;
                    wcnt++;
                }
                else if(fcnt>=3){
                    fcnt-=3;
                    wcnt++;
                }
                else return false;
            }
        }
        return true;
    }
};