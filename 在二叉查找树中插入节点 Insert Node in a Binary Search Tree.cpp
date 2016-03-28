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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        /*
        //递归：
        if(root == NULL)    return node;
        if(node->val < root->val)
            root->left = insertNode(root->left, node);
        else if(node->val > root->val)
            root->right = insertNode(root->right, node);
        return root;
        */
        //迭代：
        if(root == NULL)    return node;
        TreeNode *p = root;
        while(p != NULL)
        {
            if(node->val < p->val)
            {
                if(p->left == NULL)
                {
                    p->left = node;
                    return root;
                }
                p = p->left;
            }
            if(node->val > p->val)
            {
                if(p->right == NULL)
                {
                    p->right = node;
                    return root;
                }
                p = p->right;
            }
        }
        return root;
    }
};
