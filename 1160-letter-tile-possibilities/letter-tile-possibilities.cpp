class Solution {
public:
    void SolvePerm(int i,string str,unordered_set<string>&ans){
        if(i==str.size()){
            return;
        }


        for(int j=i;j<str.size();j++){
            swap(str[i],str[j]);
            ans.insert(str.substr(0,i+1));
            SolvePerm(i+1,str,ans);
            swap(str[i],str[j]);
        }

    }


    int numTilePossibilities(string str) {
        unordered_set<string>ans;
        SolvePerm(0,str,ans);
        return ans.size();
    }
};