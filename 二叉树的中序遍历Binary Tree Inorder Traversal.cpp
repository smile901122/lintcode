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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode *root, vector<int> &ret) {
        if (root != NULL)
        {
            traverse(root->left, ret);
            ret.push_back(root->val);
            traverse(root->right, ret);
        }
    }
};
