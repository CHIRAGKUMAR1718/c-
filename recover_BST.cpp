class Solution {
public:
    void f(vector<int>&nums,TreeNode* root){
        if(root==NULL) return;
        f(nums,root->left);
        nums.push_back(root->val);
        f(nums,root->right);
    }
    void ff(vector<int>&nums,TreeNode* root,int& idx){
        if(root==NULL) return;
        ff(nums,root->left,idx);
        root->val=nums[idx];
        idx++;
        ff(nums,root->right,idx);
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        f(nums,root);
        sort(nums.begin(),nums.end());
        int idx=0;
        ff(nums,root,idx);
    }
};