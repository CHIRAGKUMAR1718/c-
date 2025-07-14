class Solution {
public:
int v;
    vector<list<pair<int,int>>> graph;
    void add_edge(int x,int y,int wt){
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});
    }

    int dijk(int src,int target){
        unordered_map<int,int> m;
        for(int i=0;i<v;i++) m[i]=1e8;
        m[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        unordered_set<int> visited;
        while(pq.size()!=0){
            auto curr=pq.top();
            pq.pop();
            int wt=curr.first;
            int node=curr.second;
            if(visited.count(node)) continue;
            visited.insert(node);
            for(auto neigh:graph[node]){
                if(wt+neigh.second<m[neigh.first]){
                    m[neigh.first]=wt+neigh.second;
                    pq.push({m[neigh.first],neigh.first});
                }
            }
        }
        int count=0;
        for(auto i:m){
            if(i.second<=target) count++;
        }
        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int target) {
        v=n;
        graph.resize(n,list<pair<int,int>>());
        for(auto v:edges){
            int x=v[0];
            int y=v[1];
            int wt=v[2];
            add_edge(x,y,wt);
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int ct=dijk(i,target);
            v.push_back({ct,i});
        }
        sort(v.begin(),v.end());
        int check=v[0].first;
        int ans=v[0].second;
        for(auto i:v){
            if(i.first==check){
                ans=max(ans,i.second);
            }
        }
        return ans;
    }
};