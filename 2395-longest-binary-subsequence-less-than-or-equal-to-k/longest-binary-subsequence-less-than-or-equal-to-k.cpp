class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0;
        int p=1;

        int n=s.length()-1;
        for(int i=n;i>=0;i--){
          if(s[i]=='0'){
            ans++;
          }else if(p<=k){
            k-=p;
            ans++;

          }
          if(p<=k){
            p*=2;
          }
        }
        return ans;
    }
};