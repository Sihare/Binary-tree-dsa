class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

         vector<vector<pair<int, int>>> adj(10001);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                adj[grid[i][j]].push_back({i, j});
            }
        }

 
        vector<vector<vector<int>>> cost(
            k + 1, vector<vector<int>>(m, vector<int>(n, INT_MAX)));
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       greater<tuple<int, int, int, int>>>
            pq;

 
        vector<int> maxi(k + 1, -1);

 
        pq.push({0, 0, 0, 0});
        cost[0][0][0] = 0;
        while (!pq.empty()) {
            auto [c, row, col, c_k] = pq.top();
            pq.pop();
            if (c > cost[c_k][row][col])
                continue;

             if (row == m - 1 && col == n - 1)
                return c;

 
            int dx[] = {0, 1};
            int dy[] = {1, 0};
            for (int i = 0; i < 2; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int ncost = c + grid[nrow][ncol];
                    if (ncost < cost[c_k][nrow][ncol]) {
                        cost[c_k][nrow][ncol] = ncost;
                        pq.push({ncost, nrow, ncol, c_k});
                    }
                }
            }

 
            if (c_k < k) {
                int val = grid[row][col];
                int n_k = c_k + 1;

 
                for (int i = maxi[n_k] + 1; i <= val; i++) {
                    for (auto it : adj[i]) {
                        int x = it.first;
                        int y = it.second;
                        if (c < cost[n_k][x][y]) {
                            cost[n_k][x][y] = c;
                            pq.push({c, x, y, n_k});
                        }
                    }
                }
                
 
                maxi[n_k] = max(maxi[n_k], val);
            }
        }
        return 0;
    }
};