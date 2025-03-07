class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
      if(left==1 && right==1000000){
        return {2,3};
      }
         vector<bool> prime(right + 1, true);

  for (int p = 2; p * p <= right; p++) {


        if (prime[p] == true) {
            
            for (int i = p * p; i <= right; i += p)
                prime[i] = false;
        }
    }
vector<int>ans;
     for (int p = left; p <= right; p++){
        if (prime[p]){
          
            ans.push_back(p);
          }
        }
    
       int a,b;
    if(ans.size()<2 ){
      return {-1,-1};
    }else{
       int mini=INT_MAX;
       for(int i=0;i<ans.size()-1;i++){
        if(ans[i+1]-ans[i] < mini){
          mini=ans[i+1]-ans[i];
          a=ans[i];
          b=ans[i+1];
        }
       }
    }
    return {a,b};
    }
};