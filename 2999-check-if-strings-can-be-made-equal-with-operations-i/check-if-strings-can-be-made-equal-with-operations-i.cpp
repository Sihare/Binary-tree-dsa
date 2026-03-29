class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true; 
        }
        
        int n = s1.length();
        
      
        unordered_map<char, int> count;
        
        for (int i = 0; i < n; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        
        
        for (const auto& k : count) {
            if (k.second != 0) {
                return false;
            }
        }
        
        
        for (int i = 0; i < n - 2; i++) {
            if (s1[i] == s2[i + 2] && s1[i + 2] == s2[i]) {
                return true;
            }
        }
        
        return false;
    }
};