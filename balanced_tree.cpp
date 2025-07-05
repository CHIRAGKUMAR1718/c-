class Solution {
public:
    void f(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        f(root->left, v);
        v.push_back(root->val);
        f(root->right, v);
    }
    void create(TreeNode*& original, int ll, int rr, vector<int>& v) {
        if (ll > rr) return;
        int mid = (ll + rr) / 2;
        original = new TreeNode(v[mid]);
        create(original->left, ll, mid - 1, v);
        create(original->right, mid + 1, rr, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        f(root, v);
        TreeNode* original = nullptr;
        create(original, 0, v.size() - 1, v);
        return original;
    }
};
