class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            if (x == 0) arr.push_back(y);
            else if (y == side) arr.push_back(1LL * side + x);
            else if (x == side) arr.push_back(3LL * side - y);
            else arr.push_back(4LL * side - x);
        }

        sort(arr.begin(), arr.end());

        long long low = 1, high = 2LL * side;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isValid(arr, side, k, mid)) {
                ans = (int)mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool isValid(vector<long long>& arr, int side, int k, long long dist) {
        long long peri = 4LL * side;

        for (int i = 0; i < arr.size(); i++) {
            long long start = arr[i];
            long long end = start + peri - dist;

            for (int j = 0; j < k - 1; j++) {
                int next = lower(arr, start + dist);

                if (next >= arr.size() || arr[next] > end) {
                    start = -1;
                    break;
                }

                start = arr[next];
            }

            if (start >= 0) return true;
        }

        return false;
    }

    int lower(vector<long long>& arr, long long target) {
        int low = 0, high = arr.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};