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
    int n,m;
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void bfs(TreeNode* root,vector<vector<string>>& ans){
        queue<TreeNode*> q;
        q.push(root);
        queue<pair<int,int>> location;
        ans[0][(m-1)/2]=to_string(root->val);
        location.push({0,(m-1)/2});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                auto loc=location.front();
                location.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    int r=loc.first+1;
                    int c=loc.second-pow(2,n-loc.first-2);
                    ans[r][c]=to_string(curr->left->val);
                    location.push({r,c});
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    int r=loc.first+1;
                    int c=loc.second+pow(2,n-loc.first-2);
                    ans[r][c]=to_string(curr->right->val);
                    location.push({r,c});
                }
            }
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row=level(root);
        n=row;
        m=pow(2,n)-1;
        vector<vector<string>> ans(n,vector<string>(m,""));
        bfs(root,ans);
        return ans;
    }
};