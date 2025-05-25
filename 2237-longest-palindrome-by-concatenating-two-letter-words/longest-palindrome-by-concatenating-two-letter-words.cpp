class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         int res = 0;
       unordered_map<string,int> mp; 
       
       for(string s:words){  
           string p = s;
           reverse(p.begin(),p.end());
           if(mp[p]>0){  
               res+= 4;
               mp[p]--;   
           }
           else{
               mp[s]++;    
           }
       }
          
       for(auto i:mp){   
           if(i.first[0]==i.first[1] && i.second>0){  
               return res+2;   
           }
       }

       return res;
    }
};