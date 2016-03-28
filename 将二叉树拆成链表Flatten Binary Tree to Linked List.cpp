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
    void flatten(TreeNode *root) {
        // write your code here
        /*
        //method 1
        //这方法帅爆了，有点绕，但是想明白了就觉得很不错
        //不占用额外空间
        TreeNode *node = root;
        TreeNode *temp;
        while(node != NULL)
        {
            if(node->right == NULL)     node->right = node->left;
            else if(node->left != NULL)
            {
                temp = node->left;
                while(temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = node->right;
                node->right = node->left;
            }
            node->left = NULL;
            node = node->right;
        }
        */
        //method 2
        if(root == NULL)    return;
        vector<TreeNode *> list;
        preOrder(root, list);
        int n = list.size();
        for(int i = 0; i < n - 1; ++i)  //最后一个结点是整棵树最后一个结点，本来左右都是NULL
        {
            list[i]->left = NULL;
            list[i]->right = list[i + 1];
        }
    }
private:
    
    void preOrder(TreeNode *root, vector<TreeNode *> &list)
    {
        if(root == NULL)    return;
        list.push_back(root);
        preOrder(root->left, list);
        preOrder(root->right, list);
    }
};
