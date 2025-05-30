class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        priority_queue<int> pq;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            pq.push(abs(queries[i][0])+abs(queries[i][1]));
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                ans[i]=pq.top();
            }
        }
        return ans;
    }
};