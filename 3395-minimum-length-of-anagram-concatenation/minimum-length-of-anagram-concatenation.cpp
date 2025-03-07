class Solution {
public:
    int minAnagramLength(string s) {
        int size = s.length();
        int ans = size;
        for(int i=1;i<=size;i++){
            set<string>st;
            if(size%i==0){ 
                for(int j=0;j<size;j+=i){
                    string sub = s.substr(j,i);
                    sort(sub.begin(),sub.end());
                    st.insert(sub);
                }
                if(st.size()==1){
                    string w = *st.begin();
                    int n = w.length();
                    ans=min(ans,n);
                }
            }   
        }  
        return ans;
    }
};