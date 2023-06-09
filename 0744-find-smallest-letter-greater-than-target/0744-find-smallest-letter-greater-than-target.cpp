class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        return l[(upper_bound(l.begin(), l.end(), target) - l.begin()) % l.size()];
    }
};