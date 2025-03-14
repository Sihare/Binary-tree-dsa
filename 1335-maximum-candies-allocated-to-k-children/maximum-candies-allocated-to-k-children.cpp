class Solution {
public:
bool is_pos(int m,vector<int>&a,long long k){
    long long c=0;
    for(int i=0;i<a.size();i++){
        c+=(a[i]/m);
    }
    if(c>=k){
        return true;
    }else{
        return false;
    }
}
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int m=(low+high)/2;
            if(is_pos(m,candies,k)){
                ans=m;
                low=m+1;
            }else{
                high=m-1;
            }
        }
        return ans;
    }
};