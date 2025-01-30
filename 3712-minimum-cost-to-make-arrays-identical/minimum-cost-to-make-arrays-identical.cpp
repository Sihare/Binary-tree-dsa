class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
          int n = arr.size();
   bool f = false;long long  ans = 0, res = 0;
    vector<pair<int, int>> a, b;

  
    for (int i = 0; i < n; i++) {
        a.push_back({arr[i], i});
        b.push_back({brr[i], i});
        res += abs(arr[i] - brr[i]);  
    }

    // Sort both arrays to align values
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

     for (int i = 0; i < n; i++) {
        if (a[i].second != b[i].second) {
            f=true ;
        }
    }

 
    for (int i = 0; i < n; i++) {
        ans += abs(a[i].first - b[i].first);
    }

     if (f) {
        ans += k;
    }

     return min(res, ans);
    }
};