class Solution {
public:
struct trie{
    trie*left;
    trie*right;

};
 void insert(trie*root,int num){
        trie*p=root;
        for(int i=31;i>=0;i--){
            int ith=(num>>i)&1;
            if(ith==1){
                if(p->right==NULL){
                    p->right=new trie();

                }
                p=p->right;
            }
            else{
                 if(p->left==NULL){
                    p->left=new trie();

                }
                p=p->left;
            }
        }
    }
    int solve(trie*root,int num){
        trie*p=root;
        long long maxi=0;
        for(int i=31;i>=0;i--){
            int ith=(num>>i)&1;
            if(ith==1){
                if(p->left!=NULL){
                    maxi+=pow(2,i);
                    p=p->left;
                }else{
                    p=p->right;
                }
            }else{
                 if(p->right!=NULL){
                    maxi+=pow(2,i);
                    p=p->right;
                }else{
                    p=p->left;
                }
            }
        }
        return maxi;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
         vector<pair<pair<int, int>, int> > newQueries;
        for(int i = 0; i < queries.size(); i++){
            newQueries.push_back({{queries[i][0], queries[i][1]}, i});
        }
        
        sort(newQueries.begin(), newQueries.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
            return a.first.second < b.first.second;
        });
        
        sort(nums.begin(), nums.end());
        
        vector<int> res(queries.size(), -1);
        int index = 0;
        trie* myTrie = new trie();
        
        for(int i = 0; i < newQueries.size(); i++){
            int data = newQueries[i].first.first;
            int limit = newQueries[i].first.second; 
            int idx = newQueries[i].second;
            
            while(index < nums.size() && nums[index] <= limit){
                insert(myTrie,nums[index++]);
            }
            
            if(index > 0){
                res[idx] =  solve(myTrie,data);
            }
        }
        
        return res;
    }
};