class Solution {
public:
    unordered_map<int,int> m;
    int n;
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void fill(vector<int>& indegree){
        for(int i=0;i<n;i++){
            indegree[i]=graph[i].size();
        }
    }
    void bfs(vector<int>& indegree,int bob){
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==1) q.push(i);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                if(indegree[curr]==0 || curr==0 || curr==bob) continue;
                indegree[curr]--;
                for(auto neigh:graph[curr]){
                    if(indegree[neigh]==0) continue;
                    indegree[neigh]--;
                    if(indegree[neigh]==1) q.push(neigh);
                }
            }
        }
    }
    void update(int sr,int prev,bool is_odd,int count,vector<int>& amount,int total_count,vector<int>& indegree){
        if(is_odd && count==(total_count/2)) amount[sr]/=2;
        else if(count>=(total_count/2)) amount[sr]=0;
        for(auto neigh:graph[sr]){
            if(indegree[neigh]==0) continue;
            if(neigh==prev) continue;
            update(neigh,sr,is_odd,count+1,amount,total_count,indegree);
        }
    }
    void dfs(int sr,int prev,vector<int>& amount,vector<int>& indegree,int sum,int& ans){
        if(sr!=0 && indegree[sr]==1){
            ans=max(ans,sum);
            return;
        }
        for(auto neigh:graph[sr]){
            if(neigh==prev) continue;
            dfs(neigh,sr,amount,indegree,sum+amount[neigh],ans);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n=amount.size();
        graph.resize(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        vector<int> indegree(n);
        fill(indegree);
        vector<int> in=indegree;
        bfs(indegree,bob);
        int count=0;
        for(auto i:indegree) if(i>0) count++;
        bool is_odd=true;
        if(count%2==0) is_odd=false;
        update(0,-1,is_odd,0,amount,count,indegree);
        int ans=INT_MIN;
        dfs(0,-1,amount,in,amount[0],ans);
        return ans;
    }
};