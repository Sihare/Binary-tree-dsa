class Solution {
    using ll = long long;
    int n,m;
    vector<int>a,b;
    ll dp[102][102][102];
    ll solve(int i,int j,int k){
        if(k == 0) return 0;
        if(i == n || j == m){
            if(k == 0) return 0;
            return LLONG_MIN;
        }
        if(dp[i][j][k] != -4e18) return dp[i][j][k];
        ll c1 = solve(i+1,j,k);
        ll c2 = solve(i,j+1,k);
        ll c3 = solve(i+1,j+1,k-1);
        if(c3 != LLONG_MIN) c3 += (1LL*a[i]*b[j]);
        ll c4 = solve(i+1,j+1,k);
        return dp[i][j][k] = max({c1,c2,c3,c4});
    }
public:
    long long maxScore(vector<int>&nums1, vector<int>&nums2, int k) {
        n = nums1.size();
        m = nums2.size();
        a = nums1;
        b = nums2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int h = 0;h<=k;h++){
                    dp[i][j][h] = -4e18;
                }
            }
        }
        return solve(0,0,k);
    }
};