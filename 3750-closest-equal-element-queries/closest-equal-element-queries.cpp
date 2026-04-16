class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> last;
        vector<int> dp(n, n);

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            int num = nums[idx];

            if (last.count(num)) {
                int prev = last[num];
                int dist = i - prev;

                dp[idx] = min(dp[idx], dist);
                dp[prev % n] = min(dp[prev % n], dist);
            }

            last[num] = i;
        }

        vector<int> res;
        for (int q : queries) {
            res.push_back(dp[q] == n ? -1 : dp[q]);
        }
        return res;
    }
};