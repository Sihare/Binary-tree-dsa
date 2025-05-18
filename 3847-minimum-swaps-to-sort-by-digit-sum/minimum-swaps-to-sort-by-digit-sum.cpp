class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        vector<pair<pair<int,int>,int>>sorted(n);
        for(int i=0;i<n;i++){
            int sum= digitsum(nums[i]);
            sorted[i]={{sum,nums[i]},i};
        }
        sort(sorted.begin(),sorted.end());
        vector<int>pos(n);
        for(int i=0;i<n;i++){
            pos[sorted[i].second]=i;
        }
        int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]|| pos[i]==i){
                continue;
            }
            int cycles=0;
            int j=i;
            while(!vis[j]){
                vis[j]=true;
                j=pos[j];
                cycles++;
            }
            ans+=(cycles-1);
        }
        return ans;
    }
};