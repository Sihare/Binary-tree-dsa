class Solution {
public:
    
    void func(int n, string str, vector<string>&ans){
        if(str.size() == n){
            ans.push_back(str);
            return;
        }
        
        for(int i = 0; i<3;i++){
            if(str.empty()==false and 'a'+i == str.back()){
                continue;
            }
            else{
                str.push_back('a'+i);
                func(n, str, ans);
                str.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string>ans;
        string str;
        func(n, str,ans);
        
        if(ans.size()>=k){
            return ans[k-1];
        }
        
        return "";
    }
};