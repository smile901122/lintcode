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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        //递归：O(n),O(1)
        /*
        if(root == NULL)    return;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        */
        //非递归：O(n),O(n)
        //使用一个队列
        if(root == NULL)    return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            
            if(temp->left != NULL)  q.push(temp->left);
            if(temp->right != NULL)  q.push(temp->right);
        }
    }
};
