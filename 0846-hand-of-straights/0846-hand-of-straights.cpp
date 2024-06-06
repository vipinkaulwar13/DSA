class Solution {
public:
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        
        unordered_map<int, int>mp;
        
        for(int i = 0; i<n; i++){
            mp[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        
        for(int i = 0; i<hand.size(); i++){
            if(mp[hand[i]] > 0){
                mp[hand[i]]--;
                for(int j = 1; j<groupSize; j++){
                    if((mp.find(hand[i]+j) != mp.end()) && (mp[hand[i]+j] >0)) mp[hand[i]+j]--;
                    
                    else return false;   
                }
            }
        }
        return true;
    }
};