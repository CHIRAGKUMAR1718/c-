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

    int bfs(int st,int k,vector<list<int>>& graph){
        queue<int> q;
        q.push(st);
        vector<bool> visited(graph.size(),false);
        visited[st]=true;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans+=q.size();
            if(k==0) break;
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
            k--;
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        int mini=0;
        for(int i=0;i<m;i++){
            int p=k-1;
            if(p<0) break;
            int x=bfs(i,p,graph2);
            mini=max(mini,x);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int p=k;
            int x=bfs(i,p,graph1);
            ans[i]=x+mini;
        }
        return ans;
    }
};