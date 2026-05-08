class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int r=stoi(s);
         vector<bool> prime(1000+1, true);
        prime[0] = false;
        prime[1] = false;
        for (long long i=2; i<=1001; i++) {
            if (prime[i]) {
                for (long long j=i*i; j<=1001; j+=i) {
                    prime[j] = false;
                }
            }
        }
  int sum=0;
        for(int i=min(n,r);i<=max(n,r);i++){
            if(prime[i]){
                sum+=i;
            }
        }
        return sum;

    }
};