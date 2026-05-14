class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n-2;i++){
          if(nums[i]==nums[i+1]){
            return false;
          }
        }
        if(nums[n-1]==n-1){
          if(nums[n-1]!=nums[n-2]){
            return false;
          }
        }else{
          return false;
        }
        return true;
    }
};