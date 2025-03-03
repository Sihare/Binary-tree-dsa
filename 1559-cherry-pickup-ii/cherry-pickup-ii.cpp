class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> prev(n, vector<int> (n,0));
        vector<vector<int>> curr(n, vector<int> (n,0));
        for(int j1=0;j1<n;j1++) {
            for(int j2=0;j2<n;j2++) {
                if(j1==j2) prev[j1][j2]=grid[m-1][j1];
                else prev[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--) {
            for(int j1=0;j1<n;j1++) {
                for(int j2=0;j2<n;j2++) {
                    int maxi=-1e8;
                    for(int dj1=-1;dj1<2;dj1++) {
                        for(int dj2=-1;dj2<2;dj2++) {
                            int value=0;
                            if(j1==j2) value=grid[i][j1];
                            else value=grid[i][j1]+grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)value+=prev[j1+dj1][j2+dj2];
                            else value+=-1e8;
                            maxi=max(maxi,value);
                        }
                    }
                    curr[j1][j2]=maxi;
                }
            }
            prev=curr;
        }
        return prev[0][n-1];
    }
};