class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == goal[0]) { 
                string ans;
                int l = i;
                while(l < s.length()) {
                    ans += s[l];
                    l++;
                }
                l = 0;
                while(l <i) {
                    ans += s[l];
                    l++;
                }
                if(ans == goal)
                return true;
            }
        }
        return false;
    }
};
