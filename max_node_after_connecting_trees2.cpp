class Solution {
public:
    int n,m;
    vector<list<int>> graph1;
    vector<list<int>> graph2;
    void f(int s,int e){
        graph1[s].push_back(e);
        graph1[e].push_back(s);
    }
    void ff(int s,int e){
        graph2[s].push_back(e);
        graph2[e].push_back(s);
    }

    int bfs(int st,bool flag,vector<list<int>>& graph){
        queue<int> q;
        q.push(st);
        vector<bool> visited(graph.size(),false);
        visited[st]=true;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            if(flag) ans+=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh]=true;
                    }
                }
            }
            flag=!flag;
        }
        return ans;
    }

    int bfs1(int st,bool flag,vector<list<int>>& graph,vector<int>&depth){
        depth.push_back(st);
        queue<int> q;
        q.push(st);
        vector<bool> visited(graph.size(),false);
        visited[st]=true;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            if(flag) ans+=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        if(!flag) depth.push_back(neigh);
                        visited[neigh]=true;
                    }
                }
            }
            flag=!flag;
        }
        return ans;
    }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n=edges1.size()+1;
        m=edges2.size()+1;
        graph1.resize(n);
        graph2.resize(m);
        for(auto edge:edges1){
            f(edge[0],edge[1]);
        }
        for(auto edge:edges2){
            ff(edge[0],edge[1]);
        }
        int even=max(bfs(edges2[0][0],true,graph2),bfs(edges2[0][1],true,graph2));
        vector<int> ans(n);
        vector<int> d1;
        int x=bfs1(edges1[0][0],true,graph1,d1);
        for(auto i:d1) ans[i]=x+even;
        vector<int> d2;
        int y=bfs1(edges1[0][1],true,graph1,d2);
        for(auto i:d2) ans[i]=y+even;
        return ans;
    }
};