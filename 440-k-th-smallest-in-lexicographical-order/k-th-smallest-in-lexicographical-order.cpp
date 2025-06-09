class Solution {
public:
int c2(int n,long curr,long next){
    long c1=0;
    while(curr<=n){
        c1+=(next-curr);
        curr*=10;
        next*=10;
        next=min(next,(long)n+1);
    }
    return c1;
}
    int findKthNumber(int n, int k) {
        k--;
        long curr=1;
        
        while(k>0){
            int c=c2(n,curr,curr+1);
            if(c<=k){
                curr++;
                k-=c;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};