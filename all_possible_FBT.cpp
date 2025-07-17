class Solution {
public:
    unordered_map<int,vector<TreeNode*>> m;
    vector<TreeNode*> solve(int n){
        if(n%2==0) return {};
        if(n==1) return {new TreeNode(0)}; 
        if(m.find(n)!=m.end()) return m[n];
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> l=solve(i);
            vector<TreeNode*> r=solve(n-i-1);
            for(auto nodel:l){
            for(auto noder:r){
                TreeNode* root=new TreeNode(0);
                root->left=nodel;
                root->right=noder;
                ans.push_back(root);
            }
        }
        }
        return m[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans=solve(n);
        return ans;
    }
};