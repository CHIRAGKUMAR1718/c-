class Solution {
public:
    void f(TreeNode* root,string& ans){
        if(root==NULL){
            return;
        }
        ans+='('+to_string(root->val);
        if(root->left==NULL && root->right!=NULL) ans+="()";
        f(root->left,ans);
        f(root->right,ans);
        ans+=')';
    }
    string tree2str(TreeNode* root) {
        string ans="";
        f(root,ans);
        return ans.substr(1,ans.size()-2);
    }
};