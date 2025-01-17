class Solution {
public:
    int operate(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }

    vector<int> diffWaysToCompute(string s) {
       vector<int>ans;
       bool number=true;
       for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])){
            number=false;
            vector<int>left=diffWaysToCompute(s.substr(0,i));
            vector<int>right=diffWaysToCompute(s.substr(i+1,s.length()));

            for(auto x:left){
                for(auto y:right){
                    ans.push_back(operate(x,y,s[i]));
                }
            }
        }
       }
        if(number){
            ans.push_back(stoi(s));
        }
        return ans;
    }
};