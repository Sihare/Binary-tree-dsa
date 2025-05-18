class Solution {
public:
    vector<string> colStates;
    int M = 1e9 + 7;

     vector<vector<int>> dp;

    void gettingColumnStates(int m, int n, string currState, int len,
                             char prevColor) {
      
        if (len == m) {
            colStates.push_back(currState);
            return;
        }
        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevColor) {
                continue;
            }
            
            gettingColumnStates(m, n, currState + ch, len + 1, ch);
        }
    }

   
    int solve(int prevIndex, int remainingCol, int m) {
      
        if (remainingCol == 0) {
            return 1;
        }

        if (dp[remainingCol][prevIndex] != -1) {
            return dp[remainingCol][prevIndex];
        }
 
        string prevColor = colStates[prevIndex];
        int ways = 0;
        for (int i = 0; i < colStates.size(); i++) {
            if (i == prevIndex) {
                continue;
            }
            string currColor = colStates[i];
 
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (currColor[j] == prevColor[j]) {
                    isValid = false;
                    break;
                }
            }
           
            if (isValid == true) {
                ways = (ways + solve(i, remainingCol - 1, m)) % M;
            }
        }
        return dp[remainingCol][prevIndex] = ways;
    }

    int colorTheGrid(int m, int n) {
        
      
        gettingColumnStates(m, n, "", 0, '#');

         int totalColStateSize = colStates.size();
        dp = vector<vector<int>>(n + 1, vector<int>(totalColStateSize + 1, -1));

       
        int res = 0;
        for (int i = 0; i < colStates.size(); i++) {
            res = (res + solve(i, n - 1, m)) %
                  M;  
        }
        return res;
    }
};