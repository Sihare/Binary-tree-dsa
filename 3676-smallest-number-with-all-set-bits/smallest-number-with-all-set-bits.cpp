class Solution {
public:
    int smallestNumber(int n) {
        for(int mask = 1; mask < n; mask <<= 1){
            n |= mask;
        }
        return n;
    }
};