class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n=nums.size();
        int l=0,r=n-1,zero=0;
        while (l <= r) {
        if (nums[l] == 0) 
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2) 
            swap(nums[l], nums[r--]);
        else
            l++;
    }
    }
};