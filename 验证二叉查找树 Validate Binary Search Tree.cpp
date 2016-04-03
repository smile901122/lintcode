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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        /*
        //方法1
        //挺难想到
        TreeNode* prev = NULL;
        return validate(root, prev);
        */
        //方法2
        if (root == NULL) return true;
        int lower = INT_MIN;
        int upper = INT_MAX;
        return isValid(root, lower, upper);
    }
private:
    bool validate(TreeNode* node, TreeNode* &prev) 
    {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
    
    bool isValid(TreeNode *root, int lower, int upper) 
    {
        if (root == NULL)   return true;

        if (root->val <= lower || root->val >= upper)
        {
            //考虑可能有结点值是INT_MIN INT_MAX的情况
            bool left_min = (root->val == INT_MIN && root->left == NULL); 
            bool right_max = (root->val == INT_MAX && root->right == NULL);
            if(!(left_min || right_max))    return false;
        }
        
        bool isLeftValid = isValid(root->left, lower, root->val);
        bool isRightValid = isValid(root->right, root->val, upper);

        return isLeftValid && isRightValid;
    }
};
