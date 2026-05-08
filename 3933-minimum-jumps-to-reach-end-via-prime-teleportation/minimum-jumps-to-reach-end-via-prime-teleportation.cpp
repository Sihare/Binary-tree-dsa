class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        unordered_map<int,vector<int>>mp;
         int mx = *max_element(nums.begin(), nums.end());
        
        vector<bool> prime(mx+1, true);
        prime[0] = false;
        prime[1] = false;
        for (long long i=2; i<=mx; i++) {
            if (prime[i]) {
                for (long long j=i*i; j<=mx; j+=i) {
                    prime[j] = false;
                }
            }
        }
        for(int i=0;i<n;i++){
          mp[nums[i]].push_back(i);
        }

        vector<int>vis(n+1,0);
        vis[0]=1;
        queue<int>q;
        int c=0;
        q.push(0);
        
        while(!q.empty()){
          int sz=q.size();
          while(sz--){
            int i=q.front();
            q.pop();

            if(i==n-1){
              return c;
            }
            if(i-1>=0 && !vis[i-1]){
              q.push(i-1);
              vis[i-1]=1;
            }
            if(i+1<=n-1 && !vis[i+1]){
              q.push(i+1);
              vis[i+1]=1;
            }
              if(!prime[nums[i]] || s.count(nums[i])) {
                    continue;
                }

                for(int mul = nums[i]; mul <= mx; mul += nums[i]) {
                    if(!mp.contains(mul)) {
                        continue;
                    }

                    for(int &j : mp[mul]) {
                        if(!vis[j]) {
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }

                s.insert(nums[i]);
          }
          c++;
        }
        return c;
    }
};