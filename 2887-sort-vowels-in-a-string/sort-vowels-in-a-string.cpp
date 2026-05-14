class Solution {
public:
    string sortVowels(string s) {
         vector<char> vowels, consonants;
    for (char c : s) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            vowels.push_back(c);
        } else {
            consonants.push_back(c);
        }
    }

     sort(vowels.begin(), vowels.end());

     string result;
    int j = 0, i = 0;
    for (char c : s) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            result.push_back(vowels[j++]);
        } else {
            result.push_back(consonants[i++]);
        }
    }

    return result;
    }
};