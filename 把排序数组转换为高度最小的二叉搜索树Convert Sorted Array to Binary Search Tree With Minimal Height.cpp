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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(A.empty())   return NULL;
        return middleNode(A, 0, A.size() - 1);
    }
private:
    TreeNode *middleNode(vector<int> &A, int l, int r)
    {
        if(l > r)   return NULL;
        int middle = l + (r - l) / 2;
        TreeNode *root = new TreeNode(A[middle]);
        root->left = middleNode(A, l, middle - 1);
        root->right = middleNode(A, middle + 1, r);
        return root;
    }
};
