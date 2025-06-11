class Solution {
public:
 int get(int count_a, int count_b) {
        int parity_a = count_a % 2;  
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0) return 0;  
        if(parity_a == 0 && parity_b == 1) return 1;  
        if(parity_a == 1 && parity_b == 0) return 2; 

        return 3; 

    }
    int maxDifference(string s, int k) {
        int n=s.length();
  int ans=INT_MIN;
        for(char a='0';a<='4';a++){
          for(char b='0';b<='4';b++){

            if(a==b){
              continue;
            }
            int curr_a=0;
            int curr_b=0;
            vector<int>s1(4,INT_MAX);
            int prev_a=0;
            int prev_b=0;

            int l=-1,r=0;
            while(r<n){
              if(s[r]==a){
              curr_a++;
              }
              if(s[r]==b){
              curr_b++;
              }

              while(r - l >= k && (curr_a-prev_a)>=1 && (curr_b-prev_b)>=2){
                 int left=get(prev_a,prev_b);
                s1[left]=min(s1[left],prev_a-prev_b);
                l++;
                if(s[l]==a){
                  prev_a++;
                }
                if(s[l]==b){
                  prev_b++;
                }
              }
              int right=get(curr_a,curr_b);
              int s3=(right^2);
              int best=s1[s3];

              if(best!=INT_MAX){
                ans=max(ans,(curr_a-curr_b)-best);
              }
r++;
            }
          }
        }
        return ans;
    }
};