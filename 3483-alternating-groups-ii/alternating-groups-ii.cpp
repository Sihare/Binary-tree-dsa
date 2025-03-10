class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>c;
        for(int i=0;i<colors.size();i++){
            c.push_back(colors[i]);
        }
        for(int i=0;i<k-1;i++){
            c.push_back(colors[i]);
        }
        int c1=1,c2=0;
         for(int i=0;i<c.size()-1;i++){
            if(c[i]!=c[i+1]){
                c1++;
                
            }else{
               if(c1>=k){
                   c2+=c1-(k-1);
                  
                   
               }
                c1=1;
            }
        }
        if(c1>=k){
            c2+=c1-(k-1);
        }
        return c2;
    }
};