class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0,max1=0;
        long long maxdif=0;
        for(int i=0;i<nums.size();i++){
          maxi=max(maxi,maxdif*nums[i]);
          maxdif=max(maxdif,max1-nums[i]);
          max1=max(max1,(long long)nums[i]);
        }
        return maxi;
    }
};