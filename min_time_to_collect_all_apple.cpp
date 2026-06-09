class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void fill(vector<int>& indegree,int n){
        for(int i=0;i<n;i++) indegree[i]=graph[i].size();
    }
    void bfs(vector<int>&indegree,int n,vector<bool>&hasApple){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1 && hasApple[i]==false) q.push(i);
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr==0) continue;
            if(indegree[curr]==0) continue;
            indegree[curr]--;
            for(auto neigh:graph[curr]){
                if(indegree[neigh]==0) continue;
                indegree[neigh]--;
                if(indegree[neigh]==1 && hasApple[neigh]==false) q.push(neigh);
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);
        for(auto i:edges) f(i[0],i[1]);
        vector<int> indegree(n,0);
        fill(indegree,n);
        bfs(indegree,n,hasApple);
        int ans=0;
        for(auto i:indegree){
            if(i!=0) ans++;
            cout<<i<<" ";
        }
        return (ans>0)?(ans-1)*2:0;
    }
};