class Solution {
  public:
    
    void f(vector<int>&ans,Node* root){
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        f(ans,root->left);
        f(ans,root->right);
    }
    
    
    vector<int> serialize(Node *root) {
        vector<int> ans;
        f(ans,root);
        return ans;
        
    }
    
    void f(Node*& root,int& idx,int n,vector<int> &arr){
        if(idx>=n) return;
        if(arr[idx]==-1){
            idx++;
            return;
        }
        root=new Node(arr[idx++]);
        f(root->left,idx,n,arr);
        f(root->right,idx,n,arr);
    }
    
    Node *deSerialize(vector<int> &arr) {
        int n=arr.size();
        Node* root=NULL;
        int idx=0;
        f(root,idx,n,arr);
        return root;
        
    }
};