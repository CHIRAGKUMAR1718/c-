class Solution {
public:
    void bfs(vector<vector<int>>& check,TreeNode* root){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(new TreeNode(-1));
        vector<int> v;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr->val==-1){
                check.push_back(v);
                v.clear();
                if(!q.empty()) q.push(new TreeNode(-1));
            }
            else{
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> check;
        bfs(check,root);
        int count=0;
        int mini=INT_MIN;
        for(auto i:check){
            for(auto m:i){
                if(count%2!=0) break;
                if(m%2==0) return false;
                if(m<=mini) return false;
                mini=m;
            }
            mini=INT_MIN;
            count++;
        }
        int count1=0;
        int maxi=INT_MAX;
        for(auto i:check){
            for(auto m:i){
                if(count1%2==0) break;
                if(m%2!=0) return false;
                if(m>=maxi) return false;
                maxi=m;
            }
            maxi=INT_MAX;
            count1++;
        }
        return true;
    }
};