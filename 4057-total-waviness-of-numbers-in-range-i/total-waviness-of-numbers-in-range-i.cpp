class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int j=num1;j<=num2;j++){
          string k=to_string(j);
          if(k.size()<3){
            continue;
          }
          for(int i=1;i<k.size()-1;i++){
            if((k[i]>k[i-1] && k[i]>k[i+1]) || (k[i]<k[i-1] && k[i]<k[i+1])){
              ans++;
            }
          }
        }
        return ans;
    }
};