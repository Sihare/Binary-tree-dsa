class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(getDepth(root->right), getDepth(root->left)) + 1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return NULL;
        
        int r = getDepth(root->right);
        int l = getDepth(root->left);
        
        if (r == l)
            return root;
        
        if (r > l) 
            return subtreeWithAllDeepest(root->right);
        
        else 
            return subtreeWithAllDeepest(root->left);
    }
};