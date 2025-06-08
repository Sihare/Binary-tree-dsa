class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

         for (int i = 0; i < n; ++i) {
            int gcd = 0;                 
            vector<int> freq(32, 0);    
            int minp = 31;              

             for (int j = i; j < n; ++j) {
                gcd = __gcd(gcd, nums[j]);          
                
                int p = __builtin_ctz(nums[j]);     
                freq[p]++;                          
                minp = min(minp, p);                 
                
                int len = j - i + 1;                
                
              
                if (freq[minp] <= k) {
                    ans = max(ans, 2LL * gcd * len);
                }
                else {
                    ans = max(ans, 1LL * gcd * len);
                }
            }
        }

        return ans;
    }
};
