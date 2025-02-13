class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> pq ;
    long long operations = 0;
for (int num : nums) {
        pq.push(static_cast<long long>(num));
    }

    while (pq.top() < k && pq.size() >= 2) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();

         if(x+y>=k){
             pq.push(x+y);
         }else{
             pq.push(x*2 + y);
         }
        
        operations++;
    }

    return  operations;
        
    }
};