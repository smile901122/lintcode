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
    int maxPathSum(TreeNode *root) {
        // write your code here
        res = INT_MIN;
        if (root == NULL)   return res;
        um[NULL] = 0;
        singlePath(root);
        doublePath(root);
        return res;
    }
private:
    int res;
    unordered_map<TreeNode *, int> um;
    
    void singlePath(TreeNode *root) {
        if (root == NULL)   return;
        singlePath(root->left);
        singlePath(root->right);
        um[root] = max(um[root->left], um[root->right]) + root->val;
        um[root] = max(um[root], root->val);
    }
    
    void doublePath(TreeNode *root) {
        if (root == NULL)   return;
        res = max(res, um[root->left] + um[root->right] + root->val);
        res = max(res, root->val);
        doublePath(root->left);
        doublePath(root->right);
        
    }
};
