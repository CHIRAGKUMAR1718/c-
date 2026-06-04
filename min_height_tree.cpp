class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void dfs(vector<int>&indegree,int sr,int prev){
        for(auto neigh:graph[sr]){
            if(neigh!=prev){  
                dfs(indegree,neigh,sr);
                indegree[sr]++;
                indegree[neigh]++;
            }
        }
    }
    vector<int> bfs(vector<int>&indegree){
        int n=indegree.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int size=q.size();
            n-=size;
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                        indegree[neigh]-=1;
                        if(indegree[neigh]==1) q.push(neigh);
                }
            }
        } 
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        graph.resize(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        vector<int> indegree(n,0);
        dfs(indegree,0,-1);
        return bfs(indegree);
    }
};