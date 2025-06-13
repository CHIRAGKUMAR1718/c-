#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<int,int>
vector<list<pp>> graph;
void add_edge(int u,int v,int wt){
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
}
ll prism(int src,int n){
    //n -> no. of nodes;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    unordered_set<int> visited;
    vector<int>parent(n+1);
    unordered_map<int,int> m;
    for(int i=1;i<=n;i++) m[i]=INT_MAX;
    m[src]=0;
    pq.push({0,src});
    int total_node=0;//for tree it should be n-1;
    ll result=0;//sum of weights in MST;
    while(total_node<n && !pq.empty()){
        pp curr=pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        total_node++;
        result+=curr.first;
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!visited.count(neighbour.first) && m[neighbour.first]>neighbour.second){  
            pq.push({neighbour.second,neighbour.first});
            m[neighbour.first]=neighbour.second;
            parent[neighbour.first]=curr.second;
            }
        }
    }
    return result;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prism(src,n);
    return 0;
}