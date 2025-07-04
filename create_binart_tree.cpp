class Solution {
public:
    void display(TreeNode* root){
        if(root==NULL) return;
        cout<<root->val<<"  ";
        display(root->left);
        display(root->right);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        unordered_map<int,TreeNode*> m;
        unordered_set<int> isChild; 
        for(auto v:nums){
            int parent=v[0];
            int child=v[1];
            int lr=v[2];
            if(m.find(parent)==m.end())
                m[parent]=new TreeNode(parent);
            if(m.find(child)==m.end())
                m[child]=new TreeNode(child);
            if(lr==1) m[parent]->left=m[child];
            else m[parent]->right=m[child];
            isChild.insert(child);
        }
        for(auto v:nums){
            if(isChild.find(v[0])==isChild.end())
                return m[v[0]];
        }
        return NULL;
    }
};
