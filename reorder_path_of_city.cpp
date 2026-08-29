class Solution {
public:
    vector<list<pair<int,int>>> graph;
    void connect(int sr,int sc){
        graph[sr].push_back({sc,true});
        graph[sc].push_back({sr,false});
    }
    int bfs(int n){
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int count=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(!visited[neigh.first]){
                        visited[neigh.first]=true;
                        q.push(neigh.first);
                        if(neigh.second) count++;
                    }
                }
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(auto i:connections){
            connect(i[0],i[1]);
        }
        return bfs(n);
    }
};