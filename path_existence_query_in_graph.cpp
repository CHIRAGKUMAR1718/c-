class Solution {
public:
    int f(int x,vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=f(parent[x],parent);
    }
    void dsu(int x,int y,vector<int>& parent,vector<int>& rank){
        int p1=f(x,parent);
        int p2=f(y,parent);
        if(rank[p1]>=rank[p2]){
            parent[y]=p1;
            rank[p1]++;
        }else{
            rank[p2]++;
            parent[x]=p2;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        int i=0;
        int j=1;
        while(j<n){
            if(nums[j]-nums[i]<=maxDiff){
                dsu(i,j,parent,rank);
                j++;
            }else i++;
        }
        vector<bool> ans;
        for(auto v:queries){
            if(f(v[0],parent)==f(v[1],parent)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};