class Solution {
public:

    long long solve(int n,int prevTaken, int prevLen, int col,vector<vector<long long>>&pref,vector<vector<vector<long long>>>&dp,vector<vector<int>>& grid){
        if(col==n+1)
            return 0;
        if(dp[prevTaken][prevLen][col]!=-1)
            return dp[prevTaken][prevLen][col];

        long long ans = 0;
        
        for(int len=0; len<=n; len++) {
            long prevans = 0, currans = 0;

            if(prevTaken==0 && col>1 && len > prevLen) {
                prevans = pref[len][col-1] - pref[prevLen][col-1];
            }

             if(prevLen > len) {
                currans = pref[prevLen][col] - pref[len][col];
            }

            long long ans1 = currans + prevans + solve(n,1, len, col+1,pref,dp,grid);
            long long ans2 = prevans + solve(n,0, len, col+1,pref,dp,grid);

            ans = max(ans, max(ans1, ans2));
        }

        return dp[prevTaken][prevLen][col] = ans;
    }
    long long maximumScore(vector<vector<int>>& grid) {
      int n=grid.size();

      vector<vector<long long>>pref(n+1,vector<long long>(n+1));
      vector<vector<vector<long long>>>dp(2,vector<vector<long long>>(n+1,vector<long long>(n+1,-1)));

      for(int j=0; j<n; j++) {
            for(int i=1; i<=n; i++) {
                pref[i][j+1] = pref[i-1][j+1] + grid[i-1][j];
            }
        }

        return solve(n,0,0,1,pref,dp,grid);

    }
};