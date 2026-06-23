class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    bool check(int sr,vector<int>& color){
        queue<int> q;
        q.push(sr);
        color[sr]=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto neigh:graph[curr]){
                if(color[neigh]==-1){
                    color[neigh]=1-color[curr];
                    q.push(neigh);
                }else if(color[neigh]==color[curr]) return true;
            }
        }
        return false;
    }
    int bfs(int sr){
        set<int> visited;
        queue<int> q;
        q.push(sr);
        visited.insert(sr);
        int count=0;
        while(!q.empty()){
            count++;
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(!visited.count(neigh)){
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        return count;
    }
    void dfs(int sr,vector<int>& v,vector<bool>& visited){
        visited[sr]=true;
        v.push_back(sr);
        for(auto neigh:graph[sr]){
            if(visited[neigh]) continue;
            dfs(neigh,v,visited);
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.resize(n+1);
        for(auto edge:edges) f(edge[0],edge[1]);
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (check(i, color)) return -1;
            }
        }
        vector<vector<int>> connected_component;
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            vector<int> v;
            dfs(i,v,vis);
            connected_component.push_back(v);
        }
        int ans=0;
        for(auto v:connected_component){  
            int maxi=0;
        for(auto i:v){
            int x=bfs(i);
            maxi=max(maxi,x);
        }
        ans+=maxi;
        }
        return ans;
    }
};