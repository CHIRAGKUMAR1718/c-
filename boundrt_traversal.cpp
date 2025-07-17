class Solution {
  public:
    void fleft(vector<int>& ans,Node *root){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->data);
        if(root->left) fleft(ans,root->left);
        else fleft(ans,root->right);
    }
    
    void fleaf(vector<int>& ans,Node *root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        fleaf(ans,root->left);
        fleaf(ans,root->right);
    }
    
    void fright(vector<int>& ans,Node *root){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        if(root->right) fright(ans,root->right);
        else fright(ans,root->left);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        if(!(root->left==NULL && root->right==NULL)) ans.push_back(root->data);
        fleft(ans,root->left);
        fleaf(ans,root);
        fright(ans,root->right);
        return ans;
        
    }
};