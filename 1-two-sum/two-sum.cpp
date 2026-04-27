class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int>ans;
       int diff;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        int diff=target-nums[i];
        if(mp.find(diff)!=mp.end() && mp.find(diff)->second!=i){
          ans.push_back(i);
          ans.push_back(mp.find(diff)->second);
          return ans;
        }
        mp[nums[i]]=i;
       }
  return ans;
    }
};