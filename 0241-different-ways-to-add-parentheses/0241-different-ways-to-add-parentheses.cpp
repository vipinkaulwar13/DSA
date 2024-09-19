class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        
        for(int i = 0; i<expression.size(); i++){
            if(expression[i]<'0'){
                vector<int>temp1 = diffWaysToCompute(expression.substr(0, i));
                vector<int>temp2 = diffWaysToCompute(expression.substr(i+1));
                for(auto it1:temp1){
                    for(auto it2:temp2){
                        switch(expression[i]){
                            case '+':res.push_back(it1+it2); break;
                            case '-':res.push_back(it1-it2); break;
                            case '*':res.push_back(it1*it2);
                        }
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};