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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        //除了最后逆序，也可以使用栈，最后弹栈
        vector<vector<int> > res;
        if(root == NULL)    return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                TreeNode *t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left != NULL)     q.push(t->left);
                if(t->right != NULL)    q.push(t->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
