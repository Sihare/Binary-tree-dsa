class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size(); 
        int count = 0; 
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> firstSeen; 
            int j; 
            
            for (j = i; j < n; j++) {
                char curr = word[j]; 
                
                if (firstSeen.find(curr) != firstSeen.end()) {
                    if ((j - firstSeen[curr] + 1) >= 4) {
                        count++;     
                        break;       
                    }
                } else {
                    firstSeen[curr] = j;   
                }
            }
            
            i = j;  
        }
        
        return count; 
    }
};