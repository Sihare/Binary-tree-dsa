class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
         int or_all = 0;
        for (int num : nums) {
            or_all |= num;
        }
 
        int multiplier = 1 << (nums.size() - 1);

         return or_all * multiplier;
    }
};