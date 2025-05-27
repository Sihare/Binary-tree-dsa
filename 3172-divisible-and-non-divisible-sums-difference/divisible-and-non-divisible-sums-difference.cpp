class Solution {
public:
    int differenceOfSums(int n, int m) {
        if(m>n){
          return (n*(n+1))/2;
        }
            return n * (n + 1) / 2 - m * (n / m) * (n / m + 1);

    }
};