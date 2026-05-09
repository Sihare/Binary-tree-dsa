class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
          if(nums[i]<=i){
            v.push_back({nums[i],i-nums[i]});
          }

        }

         sort(begin(v), end(v), [&](auto& a, auto& b) {
            if(a.second != b.second)
                return a.second < b.second;
            
            return a.first < b.first;
        });

         vector<int> res;

        for(auto& [v, k] : v) {
            auto it = lower_bound(begin(res), end(res), v);

            if(it == end(res))
                res.push_back(v);

            else
                *it = v;
        }

        return res.size();

    }
};