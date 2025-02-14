class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=true;
                }
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && l==2){
                    dp[i][j]=true;
                }else if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
            }
        }
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-1;j++){
                if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};