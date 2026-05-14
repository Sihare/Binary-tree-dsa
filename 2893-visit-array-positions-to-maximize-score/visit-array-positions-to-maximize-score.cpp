class Solution {
public:
    
     long long int solve(vector<int>& nums, int idx, int parity, int x, vector<vector<long long int>> &memo){
        int n=nums.size();
        
        if(idx == n)
        {
          return 0;
        }  
        
        if(memo[idx][parity] != -1)
         return memo[idx][parity];
        
         long long int skip = solve(nums,idx+1,parity,x,memo);
        
         long long int take = nums[idx] - (nums[idx]%2 == parity ? 0:x) + solve(nums,idx+1,nums[idx]%2,x,memo);
        
        return memo[idx][parity] = max(skip, take);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long int>> memo(n,vector<long long int>(2,-1));
        
        return nums[0]+solve(nums,1,nums[0]%2, x, memo);
    }
};