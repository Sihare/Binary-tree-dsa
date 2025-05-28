class Solution {
public:
    int dfs(int u, int p, vector<vector<int>> &adj, int k){ 
         if(k < 0){
            return 0;
        }
        int res = 1;
        for(int v: adj[u]){
            if(v != p){
                res += dfs(v, u, adj, k - 1);
            }
        }
        return res;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        
        for(int i = 0; i < n - 1; ++i){
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i = 0; i < m - 1; ++i){
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        
        int max_target_tree2 = 0;   // the max possible target for any node in tree2 assuming distance k - 1
        for(int i = 0; i < m; ++i){
            max_target_tree2 = max(max_target_tree2, dfs(i, -1, adj2, k - 1));
        }
        
        vector<int> answer(n);
        for(int i = 0; i < n; ++i){
            answer[i] = dfs(i, -1, adj1, k) + max_target_tree2;
        }
        
        return answer;
    }
};