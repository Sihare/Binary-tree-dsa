class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> positions(26);

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != '*') {
                positions[s[i] - 'a'].push_back(i);
            } else {
                for(int j = 0 ; j < 26 ; j++) {
                    if(!positions[j].empty()) {
                        s[positions[j].back()] = '*';
                        positions[j].pop_back();
                        break;
                    }
                }
            }
        }

        string result;

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != '*') {
                result += s[i];
            }
        }

        return result;
    }
};