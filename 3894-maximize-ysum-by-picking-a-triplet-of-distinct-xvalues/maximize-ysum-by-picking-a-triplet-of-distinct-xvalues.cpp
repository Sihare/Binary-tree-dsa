#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        if (n < 3) return -1;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[x[i]] = max(mp[x[i]], y[i]);
        }

        if (mp.size() < 3) return -1;

        vector<int> bestY;
        for (auto& [key, val] : mp) {
            bestY.push_back(val);
        }

        sort(bestY.rbegin(), bestY.rend());

        return bestY[0] + bestY[1] + bestY[2];
    }
};