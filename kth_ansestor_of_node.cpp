class TreeAncestor {
public:
    vector<vector<int>> parent;
    TreeAncestor(int n, vector<int>& nums) {
        parent.resize(n,vector<int>(18,-1));
        for(int i=0;i<n;i++) parent[i][0]=nums[i];
        for(int j=1;j<18;j++){
            for(int node=0;node<n;node++){
                if(parent[node][j-1]==-1) parent[node][j]=-1;
                else parent[node][j]=parent[parent[node][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<18;i++){
            if(k & (1<<i)) node=parent[node][i];
            if(node==-1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */