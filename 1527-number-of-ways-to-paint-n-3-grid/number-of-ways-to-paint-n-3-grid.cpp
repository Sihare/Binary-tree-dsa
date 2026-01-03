class Solution {
public:
    int numOfWays(int n) {
        const int mod=1e9+7;

        long long  x=6,y=6;

        for(int i=2;i<=n;i++){
          int nx=(2*x+2*y)%mod;
          int ny=(2*x+3*y)%mod;

          x=nx;
          y=ny;
        }

        return (x+y)%mod;
    }
};