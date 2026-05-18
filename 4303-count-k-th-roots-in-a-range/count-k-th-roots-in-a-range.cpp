class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int i = 0;
        while(pow(i, k) < l)
            i++;

        int count = 0;
        while(pow(i, k) >= l && pow(i, k) <= r) i++, count++;

        return count;
    }
};