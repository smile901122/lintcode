/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        //递归解法
        if(root == NULL)    return 0;
        int depth = INT_MAX;
        if(root->left == NULL && root->right == NULL)   return 1;

        if(root->left != NULL)
            depth = min(depth, minDepth(root->left) + 1);
        if(root->right != NULL)
            depth = min(depth, minDepth(root->right) + 1);
        return depth;
    }
};
