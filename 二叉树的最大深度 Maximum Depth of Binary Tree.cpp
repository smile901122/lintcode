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
    int maxDepth(TreeNode *root) {
        // write your code here
        /*
        //解法1：递归
        if(root == NULL)    return 0;
        int depth = max(maxDepth(root->right), maxDepth(root->left)) + 1;
        return depth;
        */
        //解法2：迭代（队列）
        //最大深度为广度优先搜索的层数
        if(root == NULL)    return 0;
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                TreeNode *t = q.front();
                q.pop();
                if(t->left != NULL)     q.push(t->left);
                if(t->right != NULL)    q.push(t->right);
            }
            ++depth;
        }
        return depth;
    }
};
