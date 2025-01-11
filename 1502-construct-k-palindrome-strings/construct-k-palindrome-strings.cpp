class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()){
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        int c=0;
        for(auto i:mp){
            if(i.second%2){
                c++;
            }
        }
        return c<=k ;
    }
};