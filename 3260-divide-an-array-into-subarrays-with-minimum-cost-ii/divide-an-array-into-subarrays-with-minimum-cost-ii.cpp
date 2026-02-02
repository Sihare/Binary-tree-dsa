class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int l = nums.size();

        long long ans = LLONG_MAX, temp = 0;

        for (int i = 1; i < l; ++i) {
            if (ul < k - 1) {
                temp += nums[i];
                up.push(nums[i]);
                ++ul;
            } else {
                int m = getU();
                if (nums[i] < m) {
                    up.pop();
                    up.push(nums[i]);
                    low.push(-m);
                     temp += nums[i] - m;
                } else {
                    low.push(-nums[i]);
                }
            }

            if (ul == k - 1) {
                ans = min(temp, ans);
             }

            if (i >= dist + 1) {
                int rm = nums[i - dist];
                remove(rm, temp);
                ++del[rm];
            }
        }

        return ans + nums[0];
    }
private:
    priority_queue<int> up, low;
    unordered_map<int, int> del;
    int ul = 0;

    int getU() {
        while (!up.empty() && del[up.top()] > 0) {
            --del[up.top()];
            up.pop();
        }
        return up.top();
    }

    int getL() {
        while (!low.empty() && del[-low.top()] > 0) {
            --del[-low.top()];
            low.pop();
        }
        return low.top();
    }

    void remove(int rm, long long &temp) {
        int un = getU();
        if (rm <= un) {
            --ul;
            temp -= rm;
            if (!low.empty()) {
                int add = -getL();
                up.push(add);
                low.pop();
                temp += add;
                ++ul;
            }
        }
    }
};