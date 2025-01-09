 
class Solution {
public:
// Written by Nikhil sihare
    vector<int> rightSideView(TreeNode* root) {
       if(!root){
        return {};
       }
       vector<int>ans; 
       
        solve(root,0,ans);
        return ans;
    }

    void solve(TreeNode* root,int level,vector<int>&ans){
      if(!root){
        return;
      }
      if(level==ans.size()){
        ans.push_back(root->val);
      }
      solve(root->right,level+1,ans);
      solve(root->left,level+1,ans);
    }
};