class Solution {
public:
int count(string s , string t){
        int cnt = 0, m = s.size();
        multiset<pair<char ,char>> ms;

        for (int ind = 0; ind < m; ind++) {
            if (s[ind] != t[ind]) {
                auto it = ms.find({t[ind], s[ind]});
                if (it != ms.end()) {
                    ms.erase(it);
                    cnt++;
                }
                else {
                    ms.insert({s[ind], t[ind]});
                }
            }
        }

        return cnt + (int)ms.size();
    }
  int solve(int ind,string &word1,string &word2,int n,vector<int>&dp){
    if(ind==n){
      return 0;
    }
    if(dp[ind]!=-1){
      return dp[ind];
    }

    int mini=INT_MAX;
    for(int i=ind;i<n;i++){
      string s1=word1.substr(ind,i-ind+1);
      string s2=word2.substr(ind,i-ind+1);

      int op1=count(s1,s2);
      reverse(s1.begin(),s1.end());
      int op2=count(s1,s2);
      int rem=solve(i+1,word1,word2,n,dp);

      mini=min(mini,rem+min(op1,op2+1));

    }
    return dp[ind]=mini;
  }
    int minOperations(string word1, string word2) {
       int n=word1.size();
       vector<int>dp(n,-1);
       return solve(0,word1,word2,n,dp); 
    }
};