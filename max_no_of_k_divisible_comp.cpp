class Solution {
public:
    int ans=0;
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    int dfs(int sr,int prev,vector<int>&value,int k){
        int sum=value[sr];
        for(auto neigh:graph[sr]){
            if(neigh!=prev){
                sum+=dfs(neigh,sr,value,k);
                sum%=k;
            }
        }
        sum%=k;
        if(sum==0) ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        graph.resize(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        int x=dfs(0,-1,values,k);
        return ans; 
    }
};