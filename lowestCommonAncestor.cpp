/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        //leetcode AC
        //该种解法没有考虑如果其中有一个结点不在树中，不是很理想（该题目默认情况下可通过）
        if(root == NULL || root == p || root == q)  return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)    return root;
        if(left != NULL)    return left;
        else if(right != NULL)   return right;
        else return NULL;
        */
        if(root == NULL || p == NULL || q == NULL)  return NULL;
        
        list<TreeNode*> path1;
        bool hasP = findPath(p, root, path1);
        list<TreeNode*> path2;
        bool hasQ = findPath(q, root, path2);
        if(hasP && hasQ)    return getLastCommonNode(path1, path2);
        return NULL;
    }
private:
    //判断一个二叉树中是否包含某个结点，并输出从根节点到该结点的路径
    bool findPath(TreeNode* node, TreeNode* pNode, list<TreeNode*> &path){
        if(node == pNode){
            path.push_back(pNode);
            return true;
        }
        bool found = false;
        if(pNode->left != NULL){
            path.push_back(pNode);
            found = findPath(node, pNode->left, path);
            if(!found)  path.pop_back();
            else return true;
        }
        if(pNode->right != NULL){
            path.push_back(pNode);
            found = findPath(node, pNode->right, path);
            if(!found)  path.pop_back();
            else return true;
        }
        return false;
    }
    //找到两个链表list的第一个公共结点
    TreeNode* getLastCommonNode(const list<TreeNode*> &path1, const list<TreeNode*> &path2){
        list<TreeNode*>::const_iterator iterator1 = path1.begin();
        list<TreeNode*>::const_iterator iterator2 = path2.begin();
        TreeNode* pLast = NULL;
        while(iterator1 != path1.end() && iterator2 != path2.end() && *iterator1 == *iterator2){
            pLast = *iterator1;
            ++iterator1;
            ++iterator2;
        }
        return pLast;
    }
};
