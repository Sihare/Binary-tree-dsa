class Solution {
public:
int mod = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
    int sum =0,cnt=0,even=0,odd=0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i]; 
        if(sum%2!=0){  
            odd++;
            cnt++;
            cnt = (cnt+even)%mod;  
         }else{
            even++;
            cnt= (cnt+odd)%mod;  
         }
    }
    return cnt%mod;
    }
};