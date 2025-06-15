class Graph {
public:
    #define pp pair<int,int>
    vector<list<pp>> graph;
    int v;
    Graph(int n, vector<vector<int>>& edges) {
        v=n;
        graph.resize(n,list<pp>());
        for(auto i:edges){
            graph[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        unordered_set<int> visited;
        unordered_map<int, int> m;
        pq.push({0, node1}); // weight, node
        for(int i = 0; i < v; i++) m[i] = 1e9;
        m[node1] = 0;
        while(pq.size() != 0){
            auto curr = pq.top(); // {weight, node}
            pq.pop();
            if(visited.count(curr.second)){
                continue;
            }
            visited.insert(curr.second);
            //if(curr.second == node2) return m[node2];
            for(auto neighbour : graph[curr.second]){
                if(!visited.count(neighbour.first) && m[neighbour.first] > m[curr.second] + neighbour.second){
                    m[neighbour.first] = m[curr.second] + neighbour.second;
                    pq.push({m[neighbour.first], neighbour.first});
                }
            }
        }
        return (m[node2] == 1e9) ? -1 : m[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */