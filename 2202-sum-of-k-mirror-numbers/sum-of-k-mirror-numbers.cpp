class Solution {
public:
 string baseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string res = "";
        while(num > 0) {
            res += to_string(num%k);
            num /= k;
        }

        return res;
    }
     bool isPalin(string baseK) {
        int i = 0;
        int j = baseK.length()-1;

        while(i <= j) {
            if(baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    long long kMirror(int k, int n) {
        long long ans=0;
        int l=1;

        while(n>0){
          int left=(l+1)/2;

          long long mini=pow(10,left-1);
          long long maxi=pow(10,left)-1;

          for(long long i=mini;i<=maxi;i++){
            string a=to_string(i);
            string b=a;

            reverse(b.begin(),b.end());
            string pal="";
            if(l%2==0){
            pal=a+b;
            
            }else{
              pal=a+b.substr(1);
            }
            long long pal_num=stoll(pal);

            string c=baseK(pal_num,k);
            if(isPalin(c)){
              ans+=pal_num;
              n--;
              if(n==0){
                break;
              }
            }
          }
          l++;
        }
        return ans;
    }
};