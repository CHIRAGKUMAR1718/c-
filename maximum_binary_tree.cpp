class Solution {
public:
    void f(TreeNode*& root,int l,int r,vector<int>& nums){
        if(l>r) return;
        int idx=-1;
        int maxi=INT_MIN;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxi){
                idx=i;
                maxi=nums[i];
            }
        }
        root=new TreeNode(nums[idx]);
        f(root->left,l,idx-1,nums);
        f(root->right,idx+1,r,nums);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=nullptr;
        f(root,0,n-1,nums);
        return root;
    }
};