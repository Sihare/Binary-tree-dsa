class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        for (auto& row : box) {
            int pos = n - 1;
            
            for (int i = n - 1; i >= 0; i--) {
                if (row[i] == '*') {
                    pos = i - 1;
                }
                else if (row[i] == '#') {
                    swap(row[pos], row[i]);
                    pos--;
                }
            }
        }
        
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = box[i][j];
            }
        }
        
        return ans;
    }
};