class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(numCourses,0);
        for(auto &i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
             for (auto &ngbr : adj[node]) {
                 mp[ngbr].insert(node);
                for (auto &prereq : mp[node]) {  
                    mp[ngbr].insert(prereq);
                }

                indeg[ngbr]--;
                if (!indeg[ngbr]) {
                    q.push(ngbr);
                }
            }
        }

         int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);
            result[i] = isReachable;
        }

        return result;
    }
};