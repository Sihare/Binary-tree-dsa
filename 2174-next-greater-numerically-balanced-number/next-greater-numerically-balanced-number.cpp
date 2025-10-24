class Solution {
public:
   bool isbal(int n){
        vector<int> v(10);
        
        
        while(n){
            v[n%10]++;
            n/=10;
        }
        
        
       for(int i=0;i<10;i++){
           if(v[i] and i!=v[i]) return false;
       }
        
        return true;
    }
    int nextBeautifulNumber(int n) {
        
        for(int i=n+1;i<1e8;i++){
            
            if(isbal(i)){
                return i;
            }
        }
        return 1;
    }
};