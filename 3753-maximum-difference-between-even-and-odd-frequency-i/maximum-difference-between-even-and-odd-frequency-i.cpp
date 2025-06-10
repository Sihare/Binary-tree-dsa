class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int a1=INT_MIN;
        int a2=INT_MIN;
    int a3=INT_MAX,a4=INT_MAX;
        for(auto &i:mp){
            if(i.second%2){
                a1=max(a1,i.second);
             }else{
                 a4=min(a4,i.second);
            }
        }
        return a1-a4;
    }
};