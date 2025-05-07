class Solution {
public:
      using ll = long long;
    int minTimeToReach(vector<vector<int>>& moveTime) {
          int n = moveTime.size(), m = moveTime[0].size();
        vector dp(n + 1, vector<long long> (m + 1, 1E18));
       
        queue<pair<pair<int, int>, ll>> q;
        q.push({{0, 0}, 0});
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto now = q.front(); q.pop();
            int x = now.first.first, y = now.first.second, t = now.second;
            if (t >= dp[x][y]) continue;
            dp[x][y] = t;
            for(auto d : dirs) {
                auto nx = x + d[0], ny = y + d[1];
                if (nx >= n or ny >= m or nx < 0 or ny < 0) continue;
                q.push({{nx, ny}, max(t, moveTime[nx][ny]) + 1});
            }
        }
        return dp[n - 1][m - 1];
    }
};