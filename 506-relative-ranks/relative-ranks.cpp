class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
          int n=score.size();
          priority_queue<pair<int,int>>pq;

          for(int i=0;i<n;i++){
            pq.push({score[i],i});

          }

          int rank=1;
          vector<string>ans(n);

          while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();

            if(rank==1){
              ans[p.second]="Gold Medal";
            }
            else if(rank==2){
              ans[p.second]="Silver Medal";
            }
            else if(rank==3){
              ans[p.second]="Bronze Medal";
            }else{
              ans[p.second]=to_string(rank);
            }
            rank++;
          }
return ans;

    }
};