class Solution {
public:
    long long atMostK(string word, int k) {
        int n = word.size(), l = 0, cons = 0;
        long long cnt = 0;
        map<char, int> vowels;
        set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
        for (int r = 0; r < n; r++) {
            if (vowelsSet.find(word[r]) != vowelsSet.end())
                vowels[word[r]]++;
            else
                cons++;
            while (vowels.size() == 5 && cons > k) {
                if (vowelsSet.find(word[l]) != vowelsSet.end()) {
                    vowels[word[l]]--;
                    if (vowels[word[l]] == 0)
                        vowels.erase(word[l]);
                } else
                    cons--;
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    long long countOfSubstrings(string word, int k) {
        return atMostK(word, k) - atMostK(word, k - 1);
    }
};