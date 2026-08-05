class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
    }
    void bfs(vector<bool>& visited,int k){
        queue<int> q;
        q.push(k);
        visited[k]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(!visited[neigh]){
                        visited[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
        }
    }
    bool ff(vector<int> v,vector<bool> visited){
        for(auto i:v){  
            for(auto neigh:graph[i]){
                if(visited[neigh]) return true;
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        graph.resize(n);
        for(auto edge:invocations){
            f(edge[0],edge[1]);
        }
        vector<bool> visited(n,false);
        bfs(visited,k);
        vector<int> nv;
        for(int i=0;i<n;i++) if(!visited[i]) nv.push_back(i);
        bool flag=ff(nv,visited);
        vector<int> ans;
        if(flag){
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }else{
            for(int i=0;i<n;i++){
                if(!visited[i]) ans.push_back(i);
            }
        }
        return ans;
    }
};