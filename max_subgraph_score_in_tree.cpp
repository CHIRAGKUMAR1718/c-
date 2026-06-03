class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    vector<int> dp;
    int dfs(int sr,int prev,vector<int>& good){
        int sum=0;
        for(auto neigh:graph[sr]){
            if(neigh!=prev){
                int x=dfs(neigh,sr,good);
                if(x>0) sum+=x;
            }
        }
        sum+=(good[sr]==0)?-1:1;
        return dp[sr]=sum;
    }
    void dfs1(int sr,int prev){
        for(auto neigh:graph[sr]){
            if(neigh!=prev){
                if(dp[neigh]>0 && (dp[sr]-dp[neigh])>0) dp[neigh]+=dp[sr]-dp[neigh];
                else if(dp[neigh]<=0 && dp[sr]>0) dp[neigh]+=dp[sr];
                dfs1(neigh,sr);
            }
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        graph.resize(n);
        dp.resize(n);
        for(auto edge:edges) f(edge[0],edge[1]);
        int x=dfs(0,-1,good);
        dfs1(0,-1);
        return dp;
    }
};