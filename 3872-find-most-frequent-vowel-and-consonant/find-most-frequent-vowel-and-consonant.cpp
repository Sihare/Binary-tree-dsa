class Solution {
public:
    int maxFreqSum(string s) {
          array<int, 26> freq = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }

     const unordered_set<char> v = {'a','e','i','o','u'};

    int a = 0;
    int b = 0;

    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        if (v.count(c)) {
            a = max(a, freq[i]);
        } else {
            b = max(b, freq[i]);
        }
    }

    return a+b;
    }
};