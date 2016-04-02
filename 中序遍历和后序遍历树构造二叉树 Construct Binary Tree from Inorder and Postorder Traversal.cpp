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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return NULL;
        int n = inorder.size();
        return construct(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode *construct(vector<int> &in, vector<int> &pos, int il, int ir, int pl, int pr)
    {
        int r = pos[pr];
        TreeNode *root = new TreeNode(r);
        int index;
        for(index = 0; index < ir; ++index)
        {
            if(in[index] == r)  break;
        }
        int len;
        if(index > il)
        {
            len = index - il;
            root->left = construct(in, pos, il, index - 1, pl, pl + len - 1);
        }
        if(index < ir)
        {
            len = ir - index;
            root->right = construct(in, pos, index + 1, ir, pr - len, pr - 1);
        }
        return root;
    }
};
