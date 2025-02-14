class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxi=0,ind=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=true;
                    maxi=1;
                    ind=0;
                }
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && l==2){
                    dp[i][j]=true;
                    maxi=2;
                    ind=i;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(l>maxi){
                        maxi=l;
                        ind=i;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return s.substr(ind,maxi);
    }
};