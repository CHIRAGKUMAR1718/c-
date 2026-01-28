class Solution {
public:
    vector<list<int>> graph;
    void edge__(int src,int dest){
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    void dfs(int src,set<int>&visited,vector<int>&result){
        visited.insert(src);
        for(auto neigh:graph[src]){
            if(!visited.count(neigh)){
                result[neigh]=1+result[src]; 
                dfs(neigh,visited,result);
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        graph.resize(n,list<int>());
        for(int i=0;i<edges.size();i++) edge__(edges[i][0],edges[i][1]);
        set<int> visited;
        vector<int> dx(n,0);
        dfs(x,visited,dx);
        visited.clear();
        vector<int> dy(n,0);
        dfs(y,visited,dy);
        visited.clear();
        vector<int> dz(n,0);
        dfs(z,visited,dz);
        int ans=0;
        for(int i=0;i<n;i++){
            long long d1=dx[i];
            long long d2=dy[i];
            long long d3=dz[i];
            if((d1*d1)+(d2*d2)==(d3*d3)) ans++;
            else if((d1*d1)+(d3*d3)==(d2*d2)) ans++;
            else if((d3*d3)+(d2*d2)==(d1*d1)) ans++;
        }
        return ans;
    }
};