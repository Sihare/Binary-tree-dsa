class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        int mh = 1, mv = 1;
        int ch = 1, cv = 1;

        for (int i = 1; i < (int)h.size(); i++) {
            if (h[i] - h[i - 1] == 1) {
                ch++;
            } else {
                ch = 1;
            }
            mh = max(mh, ch);
        }

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] - v[i - 1] == 1) {
                cv++;
            } else {
                cv = 1;
            }
            mv = max(mv, cv);
        }

        int s = min(mh, mv) + 1;
        return s * s;
    }
};
