class Solution {
public:
     void f(TreeNode* root,int count,unordered_map<int,long long>&m){
        if(root==NULL) return;
        m[count]+=root->val;
        f(root->right,count+1,m);
        f(root->left,count+1,m);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_map<int,long long> m;
        f(root,1,m);
       for(auto i:m){
            pq.push(i.second);
            if(pq.size()>k) pq.pop();
       }
       if(pq.size()!=k) return -1;
       return pq.top();
    }
};