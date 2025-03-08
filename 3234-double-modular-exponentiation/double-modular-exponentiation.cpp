class Solution {
public:
 long long myPow(int base, int exponent, int mod) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }
    vector<int> getGoodIndices(vector<vector<int>>& a, int target) {
        vector<int>ans;
        int c=0;
        for(auto i:a){
          int ai=i[0];
          int bi=i[1];
          int ci=i[2];
          int mi=i[3];
          long long x=myPow(ai,bi,10);
           long long y=myPow(x,ci,mi);
           if(y==target){
            ans.push_back(c);
          }
          c++;
        }
        return ans;
    }
};