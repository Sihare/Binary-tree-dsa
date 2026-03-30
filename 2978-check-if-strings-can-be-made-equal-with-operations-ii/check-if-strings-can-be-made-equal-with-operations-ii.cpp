class Solution {
public:
    bool checkStrings(string s1, string s2) {
         if (s1.size() != s2.size()) {
        
    }

    unordered_map<char, int> hm1e, hm1o, hm2e, hm2o;

    for (int i = 0; i < s1.size(); i++) {
        if (i % 2 == 0) {
            hm1e[s1[i]]++;
            hm2e[s2[i]]++;
        } else {
            hm1o[s1[i]]++;
            hm2o[s2[i]]++;
        }
    }

    return (hm1e == hm2e) && (hm1o == hm2o);
}
};