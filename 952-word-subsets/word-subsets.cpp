class Solution {
public:
// Written By Nikhil sihare
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp;
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int>mp1;
            string str=words2[i];
            for(auto ch:str){
                mp1[ch]++;
                mp[ch]=max(mp[ch],mp1[ch]);
            }
        }

        vector<string> ans;        
        for(auto str : words1) {
            unordered_map<char,int> cur;
            for(char c : str) cur[c]++;
            
            bool ok = true;
            for(auto [ch,frq] : mp)
                if(cur[ch] < frq) {
                    ok = false; 
                    break;
                }
            
            if(ok) ans.push_back(str);
        }
        return ans;

    }
};