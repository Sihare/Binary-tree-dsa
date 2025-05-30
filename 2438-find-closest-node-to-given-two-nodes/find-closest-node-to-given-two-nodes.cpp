class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>d1(n,-1),d2(n,-1);

        queue<int>q;
        q.push(node1);
        d1[node1]=0;
        while(!q.empty()){
          int u=q.front();
          q.pop();
          if(edges[u]!=-1){
            if(d1[edges[u]]==-1){
              d1[edges[u]]=d1[u]+1;
              q.push(edges[u]);
            }
          }
        }
        q.push(node2);
        d2[node2]=0;
         while(!q.empty()){
          int u=q.front();
          q.pop();
          if(edges[u]!=-1){
            if(d2[edges[u]]==-1){
              d2[edges[u]]=d2[u]+1;
              q.push(edges[u]);
            }
          }
        }
  int mini=INT_MAX;
  int miniNode=-1;

    for(int i=0;i<n;i++){
      if(d1[i]!=-1 && d2[i]!=-1){
        int maxi=max(d1[i],d2[i]);
        if(mini>maxi){
          mini=maxi;
          miniNode=i;
        }
      }
    }
    return miniNode;
    }
};