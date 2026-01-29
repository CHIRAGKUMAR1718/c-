class Solution {
public:
    using pp=pair<int,int>;
    unordered_map<int,vector<pp>> graph;
    void edge__(int src,int dest,int wt){
        graph[src].push_back({dest,wt});
    }

    vector<long long> bfs(int src){
        vector<long long> dist(26,INT_MAX);
        dist[src]=0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,src});
        unordered_set<int> visited;
        while(pq.size()!=0){
            auto curr=pq.top();
            if(visited.count(curr.second)){
                pq.pop();
                continue;
            }
            visited.insert(curr.second);
            pq.pop();
            for(auto neigh:graph[curr.second]){
                if(!visited.count(neigh.first) && dist[neigh.first]>dist[curr.second]+neigh.second){
                    dist[neigh.first]=dist[curr.second]+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i=0;i<original.size();i++){
            int src=original[i]-'a';
            int dest=changed[i]-'a';
            int wt=cost[i];
            edge__(src,dest,wt);
        }
        long long ans=0;
        unordered_map<int,vector<long long>> m;
        set<int> s;
        for(auto i:source) s.insert(i-'a');
        for(auto i:s) m[i]=bfs(i);
        for(int i=0;i<source.size();i++){
            int src=source[i]-'a';
            int dest=target[i]-'a';
            long long x=m[src][dest];
            if(x==INT_MAX) return -1;
            ans+=x;
        }
        return ans;
    }
};