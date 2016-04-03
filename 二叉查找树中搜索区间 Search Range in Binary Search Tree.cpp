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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        //中序遍历
        vector<int> res;
        inorderDFS(root, res, k1, k2);
        return res;
    }
private:
    void inorderDFS(TreeNode *root, vector<int> &res, int k1, int k2)
    {
        if(root == NULL)    return;

        inorderDFS(root->left, res, k1, k2);
        if(root->val >= k1 && root->val <= k2)  res.push_back(root->val);
        inorderDFS(root->right, res, k1, k2);
    }
};
