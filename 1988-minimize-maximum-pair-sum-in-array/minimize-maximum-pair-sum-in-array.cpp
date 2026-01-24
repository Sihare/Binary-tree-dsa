class Solution {
public:
    int minPairSum(vector<int>& nums){
         sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1,maxi=0;
		 
        while(start<end){
            maxi=max(maxi,nums[start++]+nums[end--]);
        }
        return maxi;
    }
};