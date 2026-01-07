class Solution {
public:
    void f(TreeNode*&root,long long& sum){
        if(root==NULL) return;
        sum+=root->val;
        f(root->left,sum);
        f(root->right,sum);
        long long l=(root->left)?root->left->val:0;
        long long r=(root->right)?root->right->val:0;
        root->val+=l+r;
    }

    void solve(TreeNode* root,long long sum,long long& ans){
        if(root==NULL) return;
        long long l=(root->left)?root->left->val:0;
        long long r=(root->right)?root->right->val:0;
        long long left_break=sum-l;
        long long right_break=sum-r;
        long long x=(l*left_break);
        long long y=(r*right_break);
        ans=max(ans,x);
        ans=max(ans,y);
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);
    }

    int maxProduct(TreeNode* root) {
        long long sum=0;
        f(root,sum);
        long long ans=0;
        solve(root,sum,ans);
        return ans%1000000007;
    }
};