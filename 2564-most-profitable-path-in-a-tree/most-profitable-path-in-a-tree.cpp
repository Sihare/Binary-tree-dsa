class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>mp;
    int maxi;
    bool dfsB(int node,vector<int>&vis,int time){
        vis[node]=true;

         mp[node]=time;
        if(node==0){
            return true;
        }
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfsB(it,vis,time+1)==true){
                    return true;
                }
            }
        }
        mp.erase(node);
        return false;


    }
    void dfsA(int node,int time,int income,vector<int>&amount,vector<int>&vis){
        vis[node]=true;
        if(mp.find(node)==mp.end() || time<mp[node]){
            income+=amount[node];
        }else if(time==mp[node]){
            income+=amount[node]/2;
        }
        if(adj[node].size()==1 && node!=0){
        maxi=max(maxi,income);
        }
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfsA(it,time+1,income,amount,vis);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        maxi=INT_MIN;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(amount.size(),false);
        dfsB(bob,vis,0);
        vis.assign(amount.size(),false);
        dfsA(0,0,0,amount,vis);
        return maxi;
    }
};