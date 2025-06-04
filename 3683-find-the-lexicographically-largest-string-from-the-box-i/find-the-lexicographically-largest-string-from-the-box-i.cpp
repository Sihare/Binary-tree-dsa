class Solution {
public:
    string answerString(string word, int k) {
        int n=word.length();
        if(k==1){
            return word;
        }
        string m,curr="";
        for(int i=0;i<n;i++){
            curr=word.substr(i,n-k+1);
            if(curr>m){
                m=curr;
            }
        }

        return m;
    }
};