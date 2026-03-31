class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;

        vector<char> word(L, '?');
        vector<bool> locked(L, false);

         for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true;
                    } else {
                        return ""; 
                    }
                }
            }
        }

         for (int i = 0; i < L; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

         for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                 if (match) {
                    bool F = false;

                     for (int j = m - 1; j >= 0; j--) {
                        int idx = i + j;

                        if (locked[idx]) continue;  

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                word[idx] = c;
                                F = true;
                                break;
                            }
                        }

                        if (F) break;
                    }

                    if (!F) return "";  
                }
            }
        }

        return string(word.begin(), word.end());
    }
};