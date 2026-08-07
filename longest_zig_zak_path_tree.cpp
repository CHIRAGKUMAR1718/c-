class Solution {
public:
    int maxi=INT_MIN;
    void ff(TreeNode* root,int& val,bool flag){
        if(root==NULL) return;
        val++;
        if(flag){
            ff(root->right,val,false);
        }else ff(root->left,val,true);
    }
    void f(TreeNode* root){
        if(root==NULL) return;
        int val=0;
        ff(root,val,true);//right
        maxi=max(maxi,val);
        val=0;
        ff(root,val,false);//left
        maxi=max(maxi,val);
        f(root->left);
        f(root->right);
    }
    int longestZigZag(TreeNode* root) {
        f(root);
        return maxi-1;
    }
};