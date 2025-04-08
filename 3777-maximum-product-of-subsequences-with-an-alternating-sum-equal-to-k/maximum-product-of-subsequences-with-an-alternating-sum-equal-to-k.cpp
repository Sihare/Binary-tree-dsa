 
class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;
     int f(int i, int currSum, int product, int type, vector<int> &nums, int k, int limit) {
         if(i == nums.size()) {
            if ((currSum == k) && (type != 0) && (product <= limit))
                return product;
            return -1;
        }
        
         if(dp.count(i) && dp[i].count(currSum) && dp[i][currSum].count(product) && dp[i][currSum][product].count(type))
            return dp[i][currSum][product][type];
        
         int ans = f(i + 1, currSum, product, type, nums, k, limit);

         if(type == 0) 
            ans = max(ans, f(i + 1, currSum + nums[i], nums[i], 1, nums, k, limit));
        else if(type == 1)   
            ans = max(ans, f(i + 1, currSum - nums[i], min(product * nums[i], limit + 1), 2, nums, k, limit));
        else if(type == 2)   
            ans = max(ans, f(i + 1, currSum + nums[i], min(product * nums[i], limit + 1), 1, nums, k, limit));
 
        return dp[i][currSum][product][type] = ans;
    }
    
    int maxProduct(vector<int> &nums, int k, int limit) {   
         int sum = 0;
        for(auto &x: nums) sum += x;
        if(k > sum || k < -sum) return -1;
            
        dp.clear();  
        return f(0, 0, 0, 0, nums, k, limit);
    }
};
