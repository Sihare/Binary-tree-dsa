class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;

        // Calculate total sum
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                total += grid[i][j];
            }
        }

         if(total % 2) return false;

        long long req = total / 2;

         long long rowsum = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++){
                rowsum += grid[i][j];
            }
            if(rowsum == req) return true;
        }

         long long colsum = 0;
        for(int j = 0; j < m - 1; j++){
            for(int i = 0; i < n; i++){
                colsum += grid[i][j];
            }
            if(colsum == req) return true;
        }

        return false;
    }
};