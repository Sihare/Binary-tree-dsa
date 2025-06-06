class Solution {
public:
    
     char smaller(vector<int> &freq){
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                return ('a'+i);
            }
        }
        return ('a'+26);
    }
    
    string robotWithString(string s) {
         vector<int> freq(26, 0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        
        string ans = "";
        stack<int> st;
        
        for(int i=0; i<s.size(); i++){
             while(!st.empty() && s[st.top()] <= smaller(freq)){
                ans += s[st.top()];
                st.pop();
            }
            st.push(i);
            freq[s[i]-'a']--;
        }
        
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        
        return ans;
    }
};