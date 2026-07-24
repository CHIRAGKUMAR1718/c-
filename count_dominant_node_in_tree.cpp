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
    int ans=0;
    int f(TreeNode* root){
        if(root==NULL) return 0;
        int x=f(root->left);
        int y=f(root->right);
        int maxi=max({root->val,x,y});
        if(root->val>=maxi) ans++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int x=f(root);
        return ans;
    }
};