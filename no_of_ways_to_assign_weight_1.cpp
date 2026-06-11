class Solution {
public:
    int n;
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void bfs(vector<int>& level){
        queue<int> q;
        set<int> visited;
        q.push(1);
        visited.insert(1);
        int prev=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                level[curr-1]=prev;
                for(auto neigh:graph[curr]){
                    if(visited.count(neigh)) continue;
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
            prev++;
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        n=edges.size()+1;
        graph.resize(n+1);
        vector<int> level(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        bfs(level);
        long long ans=0;
        for(auto i:level) ans=max(ans,(long long)i);
        cout<<ans;
        int x=ans-1;
        long long os=1;
        while(x>0){
            os*=2;
            x--;
            os%=1000000007;
        }
        return os%1000000007;
    }
};