class Solution {
private:
    static constexpr int MOD = 1e9 + 7;

     long long modExp(long long base, int exponent) {
        long long result = 1;

        while (exponent) {
            if (exponent & 1) {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exponent >>= 1;
        }

        return result;
    }

public:
    int countGoodArrays(int n, int m, int k) {
     
         int upperBound = max(n, m);
        vector<long long> factorial(upperBound + 1, 1);
        vector<long long> inverse(upperBound + 1, 1);

         for (int i = 1; i <= upperBound; ++i) 
            inverse[i] = modExp(factorial[i] = factorial[i - 1] * i % MOD, MOD - 2); 

         return  factorial[n - 1] * inverse[k] % MOD * inverse[n - 1 - k] % MOD * m % MOD * modExp(m - 1, n - 1 - k) % MOD;
    }
};