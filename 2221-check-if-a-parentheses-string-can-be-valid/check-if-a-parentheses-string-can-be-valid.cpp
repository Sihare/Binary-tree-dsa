class Solution {
public:
    bool canBeValid(string s, string locked) {
        int c=0;
        if(s.length()&1){
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || locked[i]=='0'){
                c++;
            }else{
                c--;
            }
            if(c<0){
                return false;
            }
        }
        c=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){
                c++;
            }else{
                c--;
            }
            if(c<0){
                return false;
            }
        }
        return true;
    }
};