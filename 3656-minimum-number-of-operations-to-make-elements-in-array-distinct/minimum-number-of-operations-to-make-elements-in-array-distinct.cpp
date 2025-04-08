class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> last;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (last.count(num) && last[num] >= 3 * res) {
                res = (last[num] + 1 + 2) / 3;  
            }
            last[num] = i;
        }

        return res;
    }
};