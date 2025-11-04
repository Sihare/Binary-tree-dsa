class Solution {
public:
    int helper(vector<int>arr,int x){
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int ans=0;
        while(!pq.empty()&&x>0){
            int n=pq.top().second;
            int f=pq.top().first;
            pq.pop();

            ans+=n*f;
            x--;
        }
        return ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
         for (int i = 0; i <= n - k; i++) {
            vector<int> subvec(nums.begin() + i, nums.begin() + i + k); 
            int temp = helper(subvec, x);
            ans.push_back(temp);
        }
        return ans;
    }
};