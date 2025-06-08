class Solution {
public:
long long int mod=1e9+7;

    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();

        multiset<int>s;
        int j=0;
        vector<int>dp(n+1),pref(n+1);
        dp[0]=1;
        pref[0]=1;

        for(int i=1;i<=n;i++){
          s.insert(nums[i-1]);
          while(*(s.rbegin())-*(s.begin())>k){
            s.erase(s.find(nums[j]));
            j++;
          }
          dp[i]=(pref[i-1]-((j-1>=0)?pref[j-1]:0 )+mod)%mod;
          pref[i]=(pref[i-1]+dp[i])%mod;
        }
        return dp[n];
    }
};