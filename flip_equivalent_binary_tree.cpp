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
    bool f(TreeNode* root1, TreeNode* root2){
        if(root1->val!=root2->val) return false;
        if(root1->left!=NULL){
            int x=root1->left->val;
            if(root2->left!=NULL && root2->left->val==x){
                if(!f(root1->left,root2->left)) return false;
            }else if(root2->right!=NULL && root2->right->val==x){
                if(!f(root1->left,root2->right)) return false;
            }else return false;
        }
        if(root1->right!=NULL){
            int x=root1->right->val;
            if(root2->left!=NULL && root2->left->val==x){
                if(!f(root1->right,root2->left)) return false;
            }else if(root2->right!=NULL && root2->right->val==x){
                if(!f(root1->right,root2->right)) return false;
            }else return false;
        }
        return true;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL && root2!=NULL) return false;
        if(root2==NULL && root1!=NULL) return false;
        return f(root1,root2) && f(root2,root1);
    }
};