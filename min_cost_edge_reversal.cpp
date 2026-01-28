class Solution {
public:
    using pp=pair<int,int>;
    unordered_map<int,vector<pp>> graph;
    void edge__(int src,int dest,int wt){
        graph[src].push_back({dest,wt});
        graph[dest].push_back({src,2*wt});
    }
    int bfs(int src,int n){
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        unordered_set<int> visited;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,src});
        while(pq.size()!=0){
            auto curr=pq.top();
            if(visited.count(curr.second)){
                pq.pop();
                continue;
            }
            visited.insert(curr.second);
            pq.pop();
            for(auto neigh:graph[curr.second]){
                if(!visited.count(neigh.first) && dist[neigh.first]>dist[curr.second]+neigh.second){
                    dist[neigh.first]=dist[curr.second]+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++) edge__(edges[i][0],edges[i][1],edges[i][2]);
        return (bfs(0,n)==INT_MAX)?-1:bfs(0,n);
    }
};