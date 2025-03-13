class Solution {
public:
    bool f(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n=nums.size(); 
        vector<int>freq(n+1,0);         
        for(int j=0;j<k;j++){
            int left=queries[j][0];
            int right=queries[j][1];
            int val=queries[j][2];
            freq[left]+=val;
            freq[right+1]-=val;
        }
        int op=0;        
        for(int i=0;i<n;i++){
            op+=freq[i];
            if(op<nums[i])return false;             
        }
        return true;        
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {   
        int ans=-1;
        int start=0;
        int end=queries.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            int check=f(nums,queries,mid);
            if(check){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;        
    }
};