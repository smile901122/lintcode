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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> result;
        if(root == NULL)    return result;
        vector<int> path;
        path.push_back(root->val);
        findPaths(root, path, result);
        return result;
    } 
    
private: 
    void findPaths(TreeNode* root, vector<int> &path, vector<string> &result){
        if(root->right == NULL && root->left == NULL) 
        {
            string str = to_string(path[0]);
            for(int i = 1; i < path.size(); ++i)
            {
                str += "->" + to_string(path[i]);
            }
            result.push_back(str);
        }
        
        if(root->left != NULL)
        {
            path.push_back(root->left->val);
            findPaths(root->left, path, result);
            path.pop_back();
        }

        if(root->right != NULL)
        {
            path.push_back(root->right->val);
            findPaths(root->right, path, result);
            path.pop_back();
        }
    }
};
