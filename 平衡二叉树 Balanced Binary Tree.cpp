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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(maxDepth(root) == -1)    return false;
        else    return true;
    }

private:
    int maxDepth(TreeNode *root) {
        if (root == NULL)   return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (l == -1 || r == -1 || abs(l - r) > 1)
            return -1;

        return max(l, r) + 1;
    }
};
