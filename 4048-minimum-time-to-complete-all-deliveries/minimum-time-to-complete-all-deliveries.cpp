class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
    bool isvalid(long long T, vector<int>& d, vector<int>& r) {
        long long L = lcm(r[0], r[1]);
        long long neither = T / L;
        long long totalAvailable = T - neither;

        long long deliver1 = T - T / r[0];
        long long deliver2 = T - T / r[1];

        return (deliver1 >= d[0] && deliver2 >= d[1] &&
                totalAvailable >= d[0] + d[1]);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        int n = 2;

        long long low = 0, high = 1e15;
        long long ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isvalid(mid, d, r)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};