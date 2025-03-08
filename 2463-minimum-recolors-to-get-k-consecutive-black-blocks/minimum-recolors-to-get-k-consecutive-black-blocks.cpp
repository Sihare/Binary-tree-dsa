class Solution {
public:
    int minimumRecolors(string s, int k) {
       int n=s.length();
       int i=0,j=0;
       int ans=INT_MAX;
       int c=0;
       while(j<n){
        if(s[j]=='W'){
          c++;
        }
        if(j-i+1==k){
          ans=min(ans,c);
          if(s[i]=='W'){
            c--;
          }
          i++;
        }
        j++;
       }
       return ans;
    }
};