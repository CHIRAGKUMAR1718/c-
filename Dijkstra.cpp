#include<bits/stdc++.h>
using namespace std;
//SINGLE SOURCE SHORTEST PATH
#define ll long long
#define pp pair<int,int>
vector<list<pp>> graph;
void add_edge(int u,int v,int wt){
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
}
unordered_map<int,int> dijkstra(int src,int n){//O(VlogV + ElogV)
    //SIMILAR COMPLIXITY FOR PRIMS ALGORITHM TOO;
    //n -> no. of nodes;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    unordered_set<int> visited;
    vector<int>via(n);
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) m[i]=INT_MAX;//O(V)
    m[src]=0;
    pq.push({0,src});
    while(!pq.empty()){//O((V+E)logV))
        pp curr=pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!visited.count(neighbour.first) && m[neighbour.first]>m[curr.second]+neighbour.second){  
            pq.push({m[curr.second]+neighbour.second,neighbour.first});
            m[neighbour.first]=m[curr.second]+neighbour.second;
            via[neighbour.first]=curr.second;
            }
        }
    }
    return m;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> sp=dijkstra(src,n);//SP:- shortest path
    for(auto i:sp) cout<<i.first<<" "<<i.second<<endl;
    int des;
    cin>>des;
    cout<<sp[des];
    return 0;
}