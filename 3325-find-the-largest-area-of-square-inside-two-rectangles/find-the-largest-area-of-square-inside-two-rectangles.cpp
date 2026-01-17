class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res=0;

        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int minx=max(bottomLeft[i][0],bottomLeft[j][0]);
                int miny=max(bottomLeft[i][1],bottomLeft[j][1]);
                int maxx=min(topRight[i][0],topRight[j][0]);
                int maxy=min(topRight[i][1],topRight[j][1]);

                if(minx<maxx && miny<maxy){
                    long long side=min(maxx-minx,maxy-miny);
                    res=max(res,side*side);
                }
            }
        }
        return res;
    }
};