class Solution {
public:
        int mini;
 
unordered_map<int, int> mp;
int solve(string& s, int pos,vector<vector<bool>>&dp){
    int n = s.size();
    if(pos >= n) return 0;
    if(mp.count(pos)) return mp[pos];

    int dontTake = solve(s, pos+1,dp);
    int take = INT_MIN;

    for(int j=pos+mini-1; j < n; j++){
        if(dp[pos][j])
            take = max(take, 1 + solve(s, j+1,dp));
    }
    return mp[pos] = max(take, dontTake);
}

    int maxPalindromes(string s, int k) {
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
    mini=k;
    return solve(s,0,dp);
    }
};