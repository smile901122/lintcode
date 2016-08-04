    bool isSameTree(TreeNode *t1, TreeNode *t2){
        bool isNull1 = (t1 == NULL);
        bool isNull2 = (t2 == NULL);
        if(isNull1 != isNull2)  return false;
        if(isNull1 && isNull2)    return true;
        if(t1->val != t2->val)  return false;
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
