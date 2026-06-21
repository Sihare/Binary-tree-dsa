class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1 = 0;
        int xor2 = 0;
        for(int n:arr1) xor1 ^= n;
        for(int n:arr2) xor2 ^= n;
        return xor1 & xor2;
    }
};