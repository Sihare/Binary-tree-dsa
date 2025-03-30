class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
          mp[s[i]]=i;
        }
  int i=0;
       vector<int>ans;
       int k=0;
      while(i<s.length()){
        int curr=mp[s[i]];
        while(i<=curr){
          curr=max(curr,mp[s[i]]);
          i++;
        }
        ans.push_back(i-k);
        k=i;
      }
      return ans;
    }
};