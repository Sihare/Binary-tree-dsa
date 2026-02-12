class Solution {
public:
    int longestBalanced(string s) {
        
        int n = s.length();
        int m1 = 0;

        for(int i=0; i<n; ++i){
            int f[26] = {};
            int m = 0, d = 0;

            for(int j=i; j<n; ++j){
                int idx = s[j] - 'a';
                d += (f[idx] == 0);
                m = max(m, ++f[idx]);

                if(j-i+1 == d * m)
                    m1 = max(m1, j-i+1);
            }
        }

        return m1;
    }
};