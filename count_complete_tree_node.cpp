/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int lh(TreeNode* root){
        if(root==NULL) return 0;
        int h=0;
        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }
    int rh(TreeNode* root){
        if(root==NULL) return 0;
        int h=0;
        while(root!=NULL){
            h++;
            root=root->right;
        }
        return h;
    }
    int f(TreeNode* root){
        if(root==NULL) return 0;
        if(lh(root)==rh(root)) return (1<<lh(root))-1;
        int x=f(root->left);
        int y=f(root->right);
        return 1+x+y;
    }
    int countNodes(TreeNode* root) {
        return f(root);
    }
};