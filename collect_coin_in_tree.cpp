class Solution {
public:
    int n;
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void dfs(vector<int>&indegree){
        for(int i=0;i<n;i++){
            indegree[i]=graph[i].size();
        }
    }
    void bfs(vector<int>&indegree,vector<int>&coins){
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==1 && coins[i]==0) q.push(i);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                indegree[curr]=0;
                for(auto neigh:graph[curr]){
                    if(indegree[neigh]==0) continue;
                    indegree[neigh]-=1;
                    if(indegree[neigh]==1 && coins[neigh]==0) q.push(neigh);
                }
            }
        }
    }
    void bfs1(vector<int>&indegree){
        for(int round=0;round<2;round++){  
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==1) q.push(i);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            indegree[curr]=0;
            for(auto neigh:graph[curr]){
                if(indegree[neigh]>0) indegree[neigh]-=1;
            }
        }
        }
    }
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        n=edges.size()+1;
        graph.resize(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        vector<int> indegree(n,0);
        dfs(indegree);
        bfs(indegree,coins);
        bfs1(indegree);
        int ans=0;
        for(int i=0;i<n;i++){
            if(indegree[i]!=0) ans++;
        }
        ans=(ans-1)*2;
        return (ans>=0)?ans:0;
    }
};