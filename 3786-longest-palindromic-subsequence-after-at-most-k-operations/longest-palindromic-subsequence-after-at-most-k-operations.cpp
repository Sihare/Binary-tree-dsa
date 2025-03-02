class Solution {
public:
    int n;
    int dp[201][201][201];
    int rec(int i, int j, string& s, int k) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (s[i] == s[j]) {
            return dp[i][j][k] = 2 + rec(i + 1, j - 1, s, k);
        }
        int c1 = rec(i + 1, j, s, k);
        int c2 = rec(i, j - 1, s, k);
        int res = max(c1, c2);
        int temp = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
        if (temp <= k) {
            int c3 = 2 + rec(i + 1, j - 1, s, k - temp);
            res = max(res, c3);
        }
        return dp[i][j][k] = res;
    }
    int longestPalindromicSubsequence(string s, int k) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n - 1, s, k);
    }
};