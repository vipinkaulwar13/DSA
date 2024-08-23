class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int A = 0, B = 1, a, b;
        char temp;
        while(is>>a>>temp>>b){
            A = A*b + B*a;
            B*=b;
            int g =abs(__gcd(A,B));
            A/=g;
            B/=g;
        }
        return to_string(A)+'/'+to_string(B);
    }
    
};