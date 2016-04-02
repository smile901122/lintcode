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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > zLO;
        if(root == NULL)    return zLO;
        
        queue<TreeNode *> q;
        q.push(root);
        bool even = true;
        while(!q.empty())
        {
            even = !even; //奇数层时even为false;
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
            if(even)  //偶数层翻转
                reverse(level.begin(), level.end());
            zLO.push_back(level);
        }
        return zLO;
    }
};
