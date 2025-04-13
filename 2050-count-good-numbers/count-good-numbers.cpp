class Solution {
public:
     long long powerMod(int a, long long b, int mod) {
        if(b == 0)
            return 1;
        long long x = powerMod(a, b/2, mod);
        if(b % 2 == 0)
            return (x * x) % mod;
        else
            return (((a * x) % mod) * x) % mod;
     }
    
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odds=n-even;
     int mod = 1e9+7;
     long long ans=(powerMod(5,even,mod)*powerMod(4,odds,mod))%mod;
     return ans;

    }
};