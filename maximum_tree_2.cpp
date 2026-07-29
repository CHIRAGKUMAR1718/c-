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
    void f(TreeNode*& root, int val,TreeNode* temp){
        if(val>root->val){
            temp->left=root;
            root=temp;
            return;
        }
        TreeNode* temp1=root;
        TreeNode* temp2=root->right;
        bool flag=false;
        while(temp2){
            if(val>temp2->val){
                temp->left=temp2;
                temp1->right=temp;
                flag=true;
                break;
            }
            temp1=temp2;
            temp2=temp1->right;
        }
        if(flag) return;
        temp1->right=temp;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* temp=new TreeNode(val);
        if(root==NULL) return temp;
        f(root,val,temp);
        return root;
    }
};