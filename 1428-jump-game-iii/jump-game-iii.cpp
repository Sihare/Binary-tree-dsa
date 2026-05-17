class Solution {
public:
    bool solve(int n,vector<int>&arr,int i,vector<int>&dp){
        if(arr[i]==0){
            return true;
        }
        if(i>=n || i<0){
            return false;
        }

        for(int j=1;j<=arr[i];j++){
            if(solve(n,arr,j+i,dp) ||solve(n,arr,i-j,dp) ){
                return true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        if (start < 0 || start >= n || arr[start] < 0) return false;
        if (arr[start] == 0) return true;
        arr[start] *= -1;
        
        bool ans = (canReach(arr, start + arr[start]) | canReach(arr, start - arr[start]));
        return ans;
    }
};