class Solution {
public:
    long long coloredCells(int n) {
      long long a=(long long)(n)*(long long)(n);
      long long b=(long long)(n-1)*(long long)(n-1);
        return a+b ;
    }
};