class Solution {
public:
    int f(int x,vector<int>& parent){
        if(x==parent[x]) return x;
        return parent[x]=f(parent[x],parent);
    }
    void dsu(vector<int>& parent,vector<int>& rank,int sr,int sc,int wt,unordered_map<int,int>& m){
        int p1=f(sr,parent);
        int p2=f(sc,parent);
        int v1=(m.count(p1))?m[p1]:wt;
        int v2=(m.count(p2))?m[p2]:wt;
        if(rank[p1]>=rank[p2]){
            parent[p2]=p1;
            m[p1]=v1&v2&wt;
            rank[p1]++;
        }else{
            parent[p1]=p2;
            m[p2]=v1&v2&wt;
            rank[p2]++;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int,int> m;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto v:edges) dsu(parent,rank,v[0],v[1],v[2],m);
        vector<int> ans;
        for(auto v:query){
            int p1=f(v[0],parent);
            int p2=f(v[1],parent);
            if(p1!=p2) ans.push_back(-1);
            else ans.push_back(m[p1]);
        }
        return ans;
    }
};