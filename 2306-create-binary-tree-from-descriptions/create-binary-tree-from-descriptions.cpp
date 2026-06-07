
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

         unordered_map<int, TreeNode*> nodes;

         int rootVal = 0;

        for (vector<int>& desc : descriptions) {

            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];

             rootVal ^= childVal;

             if (!nodes.count(parentVal)) {
                nodes[parentVal] = new TreeNode(parentVal);

                 rootVal ^= parentVal;
            }

             if (!nodes.count(childVal)) {
                nodes[childVal] = new TreeNode(childVal);

                 rootVal ^= childVal;
            }

             if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
        }

         return nodes[rootVal];
    }
};