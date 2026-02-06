class Solution {
public:
    int countMonobit(int n) {
        int c=0;

        for(int i=0;i<20;i++){
          if(pow(2,i)-1 <= n){
            c++;
          }
        }

        return c;
    }
};