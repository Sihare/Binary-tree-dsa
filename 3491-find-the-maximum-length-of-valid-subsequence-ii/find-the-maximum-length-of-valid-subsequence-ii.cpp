class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k,1));
        int ans=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                int x=(nums[i]+nums[j])%k;
                dp[i][x]=max(dp[i][x],dp[j][x]+1);
                ans=max(ans,dp[i][x]);
            }
        }
        return ans;
    }
};