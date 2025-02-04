class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDis = 0;

        vector<vector<char>> diagonals = {
            {'N', 'E'}, 
            {'N', 'W'}, 
            {'S', 'E'}, 
            {'S', 'W'}
        };

         for (auto diag : diagonals) {
            int tempK = k;
            int dist = 0;

            for (char ch : s) {
                if (ch == diag[0] || ch == diag[1]) {
                    dist++;
                } else if (tempK > 0) {
                    dist++;
                    tempK--;
                } else {
                    dist--;
                }

                maxDis = max(maxDis, dist);
            }
        }
        
        return maxDis;
    }
};