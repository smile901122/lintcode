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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        return isSubtreeIdentical(a, b);
    }
private:
    bool isSubtreeIdentical(TreeNode* a, TreeNode* b)
    {
        if(a == NULL)
        {
            if(b == NULL)  return true;
            else return false;
        }
        else if(b != NULL)
        {
            if(a->val == b->val)
                return isSubtreeIdentical(a->left, b->left) && isSubtreeIdentical(a->right, b->right);
            else return false;
        }
        else return false;
    }
};
