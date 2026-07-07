class Solution {
public:
    int high;
    int low;
    using pp=pair<long long,long long>;
    vector<list<pp>> graph;
    void f(int sr,int sc,int wt){
        graph[sr].push_back({sc,wt});
        low=min(low,wt);
        high=max(high,wt);
    }
    bool dj(vector<bool>& online, long long k,int target){
        int n=online.size();
        unordered_map<long long,long long> m;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        unordered_set<long long> visited;
        for(int i=0;i<n;i++) m[i]=k+10;
        m[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(visited.count(curr.second)) continue;
            visited.insert(curr.second);
            for(auto neigh:graph[curr.second]){
                if(!visited.count(neigh.first) && (m[neigh.first]>(m[curr.second]+neigh.second)) && online[neigh.first] && neigh.second>=target){
                    m[neigh.first]=m[curr.second]+neigh.second;
                    pq.push({m[neigh.first],neigh.first});
                }
            }
        }
        return m[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        high=INT_MIN;
        low=INT_MAX;
        graph.resize(online.size());
        for(auto edge:edges){
            f(edge[0],edge[1],edge[2]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(dj(online,k,mid)){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};