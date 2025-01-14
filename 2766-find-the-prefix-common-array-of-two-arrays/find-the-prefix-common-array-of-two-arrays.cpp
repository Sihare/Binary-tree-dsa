class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         int n=A.size();
         vector<int>count(n+1,0);
         vector<int>ans(n);
    int c=0;
         for(int i=0;i<n;i++){
            count[A[i]]++;//yaha pr hum logo ne A array ka count rakha
            if(count[A[i]]==2){// Yeh permutation hai toh sirf 2 hii max
            //frequency ho sakti hai
                c++;
            }
            count[B[i]]++;// Same as A
            if(count[B[i]]==2){
                c++;
            }
            ans[i]=c;
         }
         return ans;
        
    }
};