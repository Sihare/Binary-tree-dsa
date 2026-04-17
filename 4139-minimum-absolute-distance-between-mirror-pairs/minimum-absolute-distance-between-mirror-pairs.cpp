class Solution {
public:
   
 
    int solve(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int minDist = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];

            if (mp.count(curr)) {
                minDist = min(minDist, i - mp[curr]);
            }

            int rev = solve(curr);
            mp[rev] = i;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
 