class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void ff(vector<int>& indegree){
        for(int i=0;i<indegree.size();i++){
            indegree[i]=graph[i].size();
        }
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        graph.resize(n);
        for(auto road:roads) f(road[0],road[1]);
        vector<int> indegree(n);
        ff(indegree);
        long long ans=0;
        sort(indegree.begin(),indegree.end());
        long long k=n;
        for(int i=n-1;i>=0;i--){
            ans+=(long long)indegree[i]*k;
            k--;
        }
        return ans;
    }
};