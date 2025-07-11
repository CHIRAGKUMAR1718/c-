class Solution {
public:
    bool f(TreeNode*& l,TreeNode*& r){
        if(l==NULL && r==NULL) return true;
        if(l==NULL && r!=NULL) return false;
        if(l!=NULL && r==NULL) return false;
        if(l->val!=r->val) return false;
        return f(l->left,r->right) && f(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* l=root;
        TreeNode* r=root;
        return f(l,r);
    }
};