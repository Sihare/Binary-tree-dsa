class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<x.size();i++){
          mp[x[i]].push_back(y[i]);
        }

        if(mp.size()<3){
          return -1;
        }
   vector<int>ans;
        for(auto &i:mp){
          vector<int>v=i.second;
        ans.push_back(*max_element(v.begin(),v.end()));
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[0]+ans[1]+ans[2];
    }
};