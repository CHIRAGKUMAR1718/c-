class Solution {
public:
    void f(TreeNode*& root,unordered_set<int>& visited){
        if(root==NULL) return;
        if(visited.count(root->val)) root->val=-1;
        f(root->left,visited);
        f(root->right,visited);
    }
    void fun(TreeNode*& temp,queue<TreeNode*>& q){
        if(temp==NULL) return;
        if(temp->val==-1){
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            temp=NULL;
            return;
        }
        fun(temp->left,q);
        fun(temp->right,q);
    }
    void ff(vector<TreeNode*>& ans,queue<TreeNode*>& q){
        while(q.size()!=0){
            TreeNode* temp=q.front();
            q.pop();
            fun(temp,q);
            if(temp) ans.push_back(temp);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& nums) {
        if(nums.size()==0) return {root};
        unordered_set<int> visited;
        for(auto i:nums) visited.insert(i);
        f(root,visited);
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> ans;
        ff(ans,q);
        return ans;
    }
};