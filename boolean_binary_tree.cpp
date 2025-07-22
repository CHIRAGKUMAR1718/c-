class Solution {
public:
    bool f(TreeNode* root){
        if(root->right==NULL && root->left==NULL){
            if(root->val==1) return true;
            return false;
        }
        if(root->val==2) return f(root->left) || f(root->right);
        else return f(root->left) && f(root->right);
    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};