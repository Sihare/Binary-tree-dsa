class Solution {
public:
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp;

    long long solve(int i, int n, int x) {
        long long val = pow(i, x);

        if (n == 0) return 1;
        if (val > n) return 0;

        if (dp[i][n] != -1)
            return dp[i][n];

        long long take = solve(i + 1, n - val, x);
        long long skip = solve(i + 1, n, x);

        return dp[i][n] = (take + skip) % mod;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<long long>(n + 1, -1));
        return solve(1, n, x);
    }
};