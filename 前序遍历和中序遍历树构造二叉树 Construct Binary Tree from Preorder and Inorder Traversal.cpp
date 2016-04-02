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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return NULL;
        int n = preorder.size();
        return construct(preorder, inorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode *construct(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir)
    {
        int r = pre[pl];
        TreeNode *root = new TreeNode(r);
        int index;
        for(index = 0; index <= ir; ++index)
        {
            if(in[index] == r)  break;
        }
        int len;
        if(index > il)
        {
            len = index - il;
            root->left = construct(pre, in, pl + 1, pl + len, il, index - 1);
        }
        if(index < ir)
        {
            len = ir - index;
            root->right = construct(pre, in, pr - len + 1, pr, index + 1, ir);
        }
        return root;
    }
};
