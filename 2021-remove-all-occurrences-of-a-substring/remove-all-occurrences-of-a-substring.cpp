class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x=s;
        int n=s.length();
        int m=part.length();

        int j=0;
        for(int i=0;i<n;i++){
          x[j]=s[i];
          j++;
          if(j>=m && x.substr(j-m,m)==part){
            j-=m;
          }
        }
        return x.substr(0,j);
    }
};