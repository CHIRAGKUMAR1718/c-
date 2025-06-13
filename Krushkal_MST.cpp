#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//RED NOTICE TO BE REMEMBER:-----
//if connected components is greater than one then it is not a tree
//so use can not use MST or kruskal algo........
class edge{
public:
int src;
int dest;
int wt;
};
int find(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x],parent);
}
void uni(int x,int y,vector<int>&parent,vector<int>&rank){
    x=find(x,parent);
    y=find(y,parent);
    if(rank[x]>=rank[y]){
        rank[x]++;
        parent[y]=x;
    }
    else{
        rank[y]++;
        parent[x]=y;
    }
}
bool cmp(edge e1,edge e2){
    return e1.wt<e2.wt;
}
ll kruskal(int n,int e,vector<edge>&v){
    sort(v.begin(),v.end(),cmp);
    vector<int> parent(n+1,0);
    vector<int> rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int count_edge=0;
    int i=0;
    ll ans=0;
    //count_edge<n-1 because it is a tree;
    while(count_edge<n-1 && i<v.size()){
        int s=v[i].src;
        int d=v[i].dest;
        s=find(s,parent);
        d=find(d,parent);
        if(s!=d){
            //therefore there is no cycle;
            uni(s,d,parent,rank);
            ans+=v[i].wt;
            count_edge++;
        }
        i++;
    }
    return ans;
}
int main(){
int n,e;
cin>>n>>e;
vector<edge> v(e);
for(int i=0;i<e;i++){
    cin>>v[i].src>>v[i].dest>>v[i].wt;
}
cout<<kruskal(n,e,v);
}