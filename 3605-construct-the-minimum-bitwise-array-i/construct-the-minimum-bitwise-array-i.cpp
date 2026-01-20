class Solution {
public:
    int findMinAns(int prime) {
        for (int x = 1; x <= prime; ++x) {
            if ((x | (x + 1)) == prime) {
                return x;
            }
        }
        return -1;  
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  

        for (int i = 0; i < n; ++i) {
            ans[i] = findMinAns(nums[i]);  
        }

        return ans;
    }
     
};