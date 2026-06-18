/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m){
        if(root==NULL) return;
        if(root->left!=NULL) m[root->left]=root;
        if(root->right!=NULL) m[root->right]=root;
        f(root->left,m);
        f(root->right,m);
    }
    vector<int> bfs( TreeNode* target, int k,unordered_map<TreeNode*,TreeNode*> m){
        set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            k--;
            while(size--){
                auto curr=q.front();
                q.pop();
                if(curr->left!=NULL && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right!=NULL && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(m[curr]->val!=-1 && !visited.count(m[curr])){
                    q.push(m[curr]);
                    visited.insert(m[curr]);
                }
            }
            if(k==0){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        unordered_map<TreeNode*,TreeNode*> m;
        m[root]=new TreeNode(-1);
        f(root,m);
        for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
        return bfs(target,k,m);
    }
};