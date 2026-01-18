class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

         vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

         for (int sz = min(m, n); sz >= 2; sz--) {
            for (int r = 0; r + sz <= m; r++) {
                for (int c = 0; c + sz <= n; c++) {

                     int target = row[r][c + sz] - row[r][c];
                    bool ok = true;

                     for (int i = 0; i < sz && ok; i++) {
                        if (row[r + i][c + sz] - row[r + i][c] != target)
                            ok = false;
                    }

                     for (int j = 0; j < sz && ok; j++) {
                        if (col[r + sz][c + j] - col[r][c + j] != target)
                            ok = false;
                    }

                     int d1 = 0, d2 = 0;
                    for (int k = 0; k < sz; k++) {
                        d1 += grid[r + k][c + k];
                        d2 += grid[r + k][c + sz - 1 - k];
                    }

                    if (d1 != target || d2 != target)
                        ok = false;

                    if (ok) return sz;
                }
            }
        }
        return 1;
    }
};