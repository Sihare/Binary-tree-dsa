class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>diff(2*limit + 2,0);
        int n=nums.size();
        for(int i=0;i<n/2;i++){
          int a=nums[i];
          int b=nums[n-1-i];

          int maxi=max(a,b)+limit;
          int mini=min(a,b)+1;

          diff[2]+=2;
          diff[2*limit+1]-=2;

          diff[mini] += (-1);
          diff[maxi+1] -= (-1);

          diff[a+b]+=(-1);
          diff[a+b+1]-=(-1);

        }
        int result = INT_MAX;

        for(int sum = 2; sum <= 2*limit; sum++) {
            diff[sum] += diff[sum-1];

            result = min(result, diff[sum]);
        }

        return result;
    }
};