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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int i = 0, j = 0;
        function<TreeNode*()> f = [&]() -> TreeNode* { 
            TreeNode* r = new TreeNode(pre[i++]); 
            if(r->val != post[j]) r->left = f(); 
            if(r->val != post[j]) r->right = f(); j++; 
            return r; 
        };
        return f();
    }
};