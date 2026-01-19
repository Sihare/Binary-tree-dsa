class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefixSum[i][j] = (
                    mat[i - 1][j - 1]
                    + prefixSum[i - 1][j] 
                    + prefixSum[i][j - 1] 
                    - prefixSum[i - 1][j - 1]
                );
            }
        }

        int side = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            for(int k = side + 1; i + k <= n && j + k <= m; k++) {
                int sum = (
                    prefixSum[i + k][j + k]
                    - prefixSum[i][j + k]
                    - prefixSum[i + k][j]
                    + prefixSum[i][j]
                );

                if(sum <= threshold) {
                    side = k;
                } else break;
            }
        }
        return side;
    }
};