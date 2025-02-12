class Solution {
public:
int solve(int n){
    int sum=0;
    while(n>0){
        int k=n%10;
        sum+=k;
        n/=10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            mp[solve(nums[i])].push_back(nums[i]);
        }
        int sum=-1;
        for(auto &i:mp){

            int n=i.second.size();
            if(n>=2){
            vector<int>v=i.second;
        priority_queue<int>q;
            for(int i=0;i<n;i++){
                q.push(v[i]);
            }
        int a=q.top();
        q.pop();
    int b=q.top();
    q.pop();
    sum=max(sum,a+b);
            }
        }
        return sum;
    }
};