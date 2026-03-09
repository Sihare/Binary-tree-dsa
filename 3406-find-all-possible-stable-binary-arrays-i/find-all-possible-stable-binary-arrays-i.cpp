class Solution {
public:
   int numberOfStableArrays(int zero, int one, int limit) {
    const int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));
     dp[0][0][0] = dp[0][0][1] = 1;
    for (int m = 0; m <= zero; m++) {
        for (int n = 0; n <= one; n++) {
            for (int k = 1; k <= limit; k++) {
                if (m >= k) {
                     dp[m][n][0] = (dp[m][n][0] + dp[m-k][n][1]) % mod;
                }
                if (n >= k) {
                     dp[m][n][1] = (dp[m][n][1] + dp[m][n-k][0]) % mod;
                }
            }
        }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % mod;
}
};