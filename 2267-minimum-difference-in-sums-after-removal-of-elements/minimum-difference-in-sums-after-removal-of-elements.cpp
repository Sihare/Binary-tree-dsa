class Solution {
public:
    typedef pair<int, int> P;
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int n = size / 3;

 
        vector<long long> minLeftSum(size, 0);
        vector<long long> maxRightSum(size, 0);

        
        priority_queue<int> maxHeap;
        long long minSum = 0;

         for (int i = 0; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            minSum += nums[i];
 
            if (maxHeap.size() > n) {
                int top = maxHeap.top();
                minSum = minSum - top;
                maxHeap.pop();
            }
 
            minLeftSum[i] = minSum;
        }

        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long maxSum = 0;
        for (int i = size - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            maxSum += nums[i];

            if (minHeap.size() > n) {
                int top = minHeap.top();
                maxSum = maxSum - top;
                minHeap.pop();
            }

             maxRightSum[i] = maxSum;
        }

         long long res = LLONG_MAX;
        for (int i = n - 1; i <= 2 * n - 1; i++) {
            res = min(res, (minLeftSum[i] - maxRightSum[i + 1]));
        }
        return res;
    }
};