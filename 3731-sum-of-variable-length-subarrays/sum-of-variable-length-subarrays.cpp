class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int k=max(0,i-nums[i]);
            for(int j=k;j<=i;j++){
                sum+=nums[j];
            }
        }
        return sum;
    }
};