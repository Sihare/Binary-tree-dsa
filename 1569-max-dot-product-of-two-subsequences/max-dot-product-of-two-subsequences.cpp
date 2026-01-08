class Solution {
public:
    vector<vector<int>> dp;
    vector<int> a, b;
    int n, m;

    int solve(int i, int j) {
        if (i == n || j == m)
            return INT_MIN;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int prod = a[i] * b[j];

        int take = prod;
        int next = solve(i + 1, j + 1);
        if (next > 0)
            take += next;

        int skipA = solve(i + 1, j);
        int skipB = solve(i, j + 1);

        return dp[i][j] = max({take, skipA, skipB});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();

        dp.assign(n, vector<int>(m, INT_MIN));
        return solve(0, 0);
    }
};
