class Solution {
public:
    void dfs(TreeNode*& root, int& target){
        if(root==NULL) return;
        dfs(root->right,target);
        dfs(root->left,target);
        if(root->right==NULL && root->left==NULL){
            if(root->val==target) root=NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return root;
        if(root->left==NULL && root->right==NULL && root->val==target) return NULL;
        dfs(root,target);
        return root;
    }
};