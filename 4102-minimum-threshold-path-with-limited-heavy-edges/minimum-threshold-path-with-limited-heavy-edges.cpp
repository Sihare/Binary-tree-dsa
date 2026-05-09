class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        int n0=n;
        vector<vector<pair<int,int>>> g(n0);

        int hi=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            hi=max(hi,w);
        }

        auto ok=[&](int t){
            const int INF=1e9;
            vector<int> d(n0,INF);
            queue<int> q;
            d[source]=0;
            q.push(source);

            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(auto &[v,w]:g[u]){
                    int c=(w>t);
                    if(d[u]+c<d[v]){
                        d[v]=d[u]+c;
                        if(c==0)q.push(v);
                        else q.push(v);
                    }
                }
            }

            return d[target]<=k;
        };

        if(!ok(hi))return -1;

        int lo=0,ans=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ok(mid)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
            }

        return ans;
    }
};