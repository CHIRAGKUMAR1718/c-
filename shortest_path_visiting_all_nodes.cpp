class Solution {
public:
    int n;
    int bfs(vector<vector<int>>& graph){
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            visited.insert({i,mask});
            q.push({i,mask});
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                if(curr.second==((1<<n)-1)) return ans;
                int mask_curr=curr.second;
                for(auto neigh:graph[curr.first]){
                    int mask_neigh=(1<<neigh);
                    int mask=mask_curr | mask_neigh;
                    if(!visited.count({neigh,mask})){
                        visited.insert({neigh,mask});
                        q.push({neigh,mask});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size();
        return bfs(graph);
    }
};