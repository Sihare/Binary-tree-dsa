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

    // Sort vowels
    sort(vowels.begin(), vowels.end());

    // Build the resulting string
    string result;
    int vowelIndex = 0, consonantIndex = 0;
    for (char c : s) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            result.push_back(vowels[vowelIndex++]);
        } else {
            result.push_back(consonants[consonantIndex++]);
        }
    }

    return result;
    }
};