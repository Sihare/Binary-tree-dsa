/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// Written By Nikhil sihare
    int p_ind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1);
    }
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[p_ind]);
        p_ind++;
        int pos=0;
        for(int i=s;i<=e;i++){
            if(inorder[i]==node->val){
                pos=i;
                break;
            }
        }
        node->left=solve(preorder,inorder,s,pos-1);
        node->right=solve(preorder,inorder,pos+1,e);
        return node;
    }
};