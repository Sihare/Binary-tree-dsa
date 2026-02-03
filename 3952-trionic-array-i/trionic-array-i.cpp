class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int n=nums.size();
        int i=1;
        int p=0,q=0,r=0;
        while(i<n&&nums[i-1]<nums[i])
        {
            i++;
            p=i;
        }
        while(i<n&&nums[i-1]>nums[i])
        {
            i++;
            q=i;
        }
        while(i<n&&nums[i-1]<nums[i])
        {
            i++;
            r=i;
        }
        if (i == n && p > 1 && q > p && r > q) return true;
        return false;
    }
 };