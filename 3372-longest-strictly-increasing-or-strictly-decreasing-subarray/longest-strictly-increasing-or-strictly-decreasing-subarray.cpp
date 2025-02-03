class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int c1=1,c2=1;
        int maxi1=0,maxi2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                c1++;
            }else{
                maxi1=max(maxi1,c1);
                c1=1;
            }
        }
        maxi1=max(maxi1,c1);
         for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                c2++;
            }else{
                maxi2=max(maxi2,c2);
                c2=1;
            }
        }
        maxi2=max(maxi2,c2);
        return max(maxi1,maxi2);
    }
};