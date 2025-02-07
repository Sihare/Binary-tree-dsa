class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         unordered_map<int, int> b1;   
        unordered_map<int, int> c1;  
        unordered_set<int> d1;   
        vector<int> ans(queries.size());  
        
        for (int i = 0; i < queries.size(); ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            
            if (b1.find(ball) != b1.end()) {
                int p1 = b1[ball];
                c1[p1]--;
                if (c1[p1] == 0) {
                    d1.erase(p1);
                }
            }
            
            b1[ball] = color;
            c1[color]++;
            d1.insert(color);
            
            ans[i] = d1.size();
        }
        
        return ans;
    }
};