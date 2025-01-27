class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int MOD = 1e9 + 7;

        // Create a 3D DP table
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));

        // Base case: when the array is fully built
        for (int maxSoFar = 0; maxSoFar <= m; ++maxSoFar) {
            dp[n][k][maxSoFar] = 1; // Valid if we achieve exactly `k` search cost
        }

        // Fill the DP table bottom-up
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int searchCost = k; searchCost >= 0; --searchCost) {
                for (int maxSoFar = 0; maxSoFar <= m; ++maxSoFar) {
                    int result = 0;

                    // Try all possible values for the current position
                    for (int i = 1; i <= m; ++i) {
                        if (i > maxSoFar) {
                            // Increment search cost as `i` becomes the new maximum
                            if (searchCost + 1 <= k) {
                                result = (result + dp[idx + 1][searchCost + 1][i]) % MOD;
                            }
                        } else {
                            // Keep the same search cost
                            result = (result + dp[idx + 1][searchCost][maxSoFar]) % MOD;
                        }
                    }

                    dp[idx][searchCost][maxSoFar] = result;
                }
            }
        }

        // The result is stored in dp[0][0][0]
        return dp[0][0][0];
    }
};
