class Solution {
public:
    int minimumDeletions(string s) {
    int n=s.length();
    stack<char> stk;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if (!stk.empty() && stk.top()=='b' && s[i]=='a')
            stk.pop(),c++;
        else stk.push(s[i]);
    }
    return c;
}
};