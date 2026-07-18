class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
    }
    void fill(vector<int>& indegree,vector<vector<int>>& relations){
        for(auto edge:relations){
            indegree[edge[1]]++;
        }
    }
    int bfs(vector<int>& indegree,vector<int>& time){
        queue<int> q;
        vector<int> maxtime(indegree.size(),0);
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                maxtime[i]=time[i-1];
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    int x=maxtime[curr]+time[neigh-1];
                    maxtime[neigh]=max(maxtime[neigh],x);
                    indegree[neigh]--;
                    if(indegree[neigh]==0){
                        q.push(neigh);
                    }
                }
            }
        }
        int sum=0;
        for(auto ele:maxtime) sum=max(sum,ele);
        return sum;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        graph.resize(n+1);
        for(auto edge:relations) f(edge[0],edge[1]);
        vector<int> indegree(n+1,0);
        fill(indegree,relations);
        return bfs(indegree,time);
    }
};