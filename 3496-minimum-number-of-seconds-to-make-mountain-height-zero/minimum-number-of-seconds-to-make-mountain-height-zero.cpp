class Solution {
public:
  bool check(int h,long long m,vector<int>&a){
    long long h1=0;
    for(int k:a){
      h1+=(long long)((sqrt(1+8.0*m/k)-1)/2);
      if(h1>=h){
        return true;
      }
    }
    return h1>=h;
  }
    long long minNumberOfSeconds(int h, vector<int>& a) {
        long long ans=0;
        long long l=1;
        long long r=1e12*(long long)h/a.size();

        while(l<=r){
          long long m=l+(r-l)/2;
          if(check(h,m,a)){
            ans=m;
            r=m-1;

          }else{
            l=m+1;
          }
        }
        return ans;
    }
};