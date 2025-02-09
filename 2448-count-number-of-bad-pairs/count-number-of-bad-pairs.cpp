class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long n=nums.size();
        long long c=0;
        long long ans=1ll*(n*(n-1))/2;
        for(int i=0;i<nums.size();i++){
            c+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return ans-c;
    }
};