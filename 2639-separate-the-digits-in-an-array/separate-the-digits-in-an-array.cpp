class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
          string k=to_string(nums[i]);
          for(int i=0;i<k.length();i++){
            ans.push_back(k[i]-'0');
          }
        }

        return ans;
    }
};