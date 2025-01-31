class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int last = INT_MIN;
        int count = 0;

        for (int n : nums) {
            int adj = std::max(n - k, last + 1);
            if (adj <= n + k) {
                last = adj;
                ++count;
            }
        }

        return count;

    }
};