class Solution {
public:
    vector<list<int>> graph;
    void f(int sr,int sc){
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }
    void dfs(int sr,int prev,vector<int>& ans,string& start,string& target,unordered_map<string,int>& m){
        for(auto neigh:graph[sr]){
            if(neigh==prev) continue;
            dfs(neigh,sr,ans,start,target,m); 
        }
        if(sr!=0 && start[sr]!=target[sr]){
            ans.push_back(m[to_string(sr)+"_"+to_string(prev)]);
            if(target[sr]=='0') target[sr]='1';
            else target[sr]='0';  
            if(target[prev]=='0') target[prev]='1';
            else target[prev]='0';
        }
    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        unordered_map<string,int> m;
        graph.resize(n);
        int idx=0;
        for(auto edge:edges){
            f(edge[0],edge[1]);
            m[to_string(edge[0])+"_"+to_string(edge[1])]=idx;
            m[to_string(edge[1])+"_"+to_string(edge[0])]=idx;
            idx++;
        }
        vector<int> ans;
        dfs(0,-1,ans,start,target,m);
        sort(ans.begin(),ans.end());
        if(start[0]==target[0]) return ans;
        return {-1};
    }
};