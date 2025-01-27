class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>n;
        n.push_back(pairs[0][1]);
        for(int i=1;i<pairs.size();i++){
            n.push_back(pairs[i][0]);
        }
        int maxi=1;
        vector<int>dp(n.size(),1);
        for(int i=0;i<n.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
        
    }
};