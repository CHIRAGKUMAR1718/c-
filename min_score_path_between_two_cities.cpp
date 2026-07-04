class Solution {
public:
    vector<list<pair<int,int>>> graph;
    void f(int sr,int sc,int wt){
        graph[sr].push_back({sc,wt});
        graph[sc].push_back({sr,wt});
    }
    int bfs(int& n){
        int mini=INT_MAX;
        set<int> visited;
        queue<int> q;
        q.push(1);
        visited.insert(1);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto neigh:graph[curr]){
                mini=min(mini,neigh.second);
                if(!visited.count(neigh.first)){
                    visited.insert(neigh.first);
                    q.push(neigh.first);
                }
            }
        }
        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        graph.resize(n+1);
        for(auto v:roads) f(v[0],v[1],v[2]);
        return bfs(n);
    }
};