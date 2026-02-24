class Solution {
public:
    string f(vector<TreeNode*>& ans,unordered_map<string,int>& m,TreeNode* root){
        if(root==NULL) return "N";
        string s=to_string(root->val)+","+f(ans,m,root->left)+","+f(ans,m,root->right);
        if(m[s]==1) ans.push_back(root);
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> m;
        string yoo=f(ans,m,root);
        return ans;
    }
};