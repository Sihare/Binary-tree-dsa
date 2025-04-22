class Solution {
public:
    int mod=pow(10,9)+7;

    int Comb(int n, int k, vector<vector<int>>& memo)
    {
        if(k == 0) return 1;
        if(n == 0) return 0;
        
        if(memo[n][k] != 0)
            return memo[n][k];
        
        memo[n][k] = Comb(n-1, k, memo)+Comb(n-1, k-1, memo);
        memo[n][k] %= mod;
        return memo[n][k];
    }
    int count(int val,int ind,int n,int maxV,vector<vector<int>> &dp,vector<vector<int>> &memo){

        if(ind==n ){
            return 1;
        }
        
        int j=2;
        if(dp[ind][val]!=-1){
            return dp[ind][val];
        }
        
        long long ans=0;
        bool flag=0;
        
        while(val*j<=maxV){
            ans=(ans%mod+count(val*j,ind+1,n,maxV,dp,memo)%mod)%mod;
            j++;

            if(val*j>maxV){
                ans=(ans%mod+Comb(n-1,ind-1,memo)%mod)%mod;
            }
            flag=1;
        }
        
        if(flag==0){
            if(val*j>maxV){
                ans=(ans%mod+Comb(n-1,ind-1,memo)%mod)%mod;
            }
        }
        
        dp[ind][val]=ans%mod;
        return dp[ind][val];
        
    }
    int idealArrays(int n, int maxV) {
        
        vector<vector<int>> dp(15,vector<int>(maxV+1,-1) );
        vector<vector<int>> memo(n+1,vector<int>(15,0));
        
        long long ans=0;
        
        for(int i=1;i<=maxV;i++)
        ans=(ans%mod+count(i,1,n,maxV,dp,memo)%mod)%mod;
        
        return ans;
    }
};