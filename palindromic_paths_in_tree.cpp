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
    bool ff(unordered_map<int,int>& m){
        int count=0;
        for(auto i:m){
            if(i.second%2!=0) count++;
        }
        return count<=1;
    }
    void f(TreeNode* root,unordered_map<int,int>& m){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            m[root->val]++;
            if(ff(m)) ans++;
            m[root->val]--;
            return;
        }
        m[root->val]++;
        f(root->left,m);
        f(root->right,m);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> m;
        f(root,m);
        return ans;
    }
};