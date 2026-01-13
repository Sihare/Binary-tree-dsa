class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
         long double ans = 0.0L;
         long double  Y = numeric_limits<long double>::max();
        long double Top = -numeric_limits<long double>::max();
        
        for (auto &sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            ans += (long double)l * l;
            Y = min( Y, (long double)y);
            Top = max( Top, (long double)y + l);
        }
        long double h = ans / 2.0L;
        
         long double low =  Y, high = Top;
        for (int i = 0; i < 100; i++) {  
            long double mid = (low + high) / 2.0L;
            long double a1 = 0.0L;
            for (auto &sq : squares) {
                long double y = sq[1], l = sq[2];
                long double top = y + l;
                if (mid <= y) {
                     a1 += l * l;
                } else if (mid < top) {
                     a1 += (top - mid) * l;
                }
             }
             if (a1 > h) {
                 low = mid;
            } else {
                high = mid;
            }
        }
        return (double)((low + high) / 2.0L);
    }
};