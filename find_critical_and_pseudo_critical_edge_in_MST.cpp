class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int f(int x,vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=f(parent[x],parent);
    }
    void un(int sr,int sc,vector<int>& parent,vector<int>& rank){
        int x=f(sr,parent);
        int y=f(sc,parent);
        if(rank[x]>=rank[y]){
            rank[x]++;
            parent[y]=x;
        }else{
            rank[y]++;
            parent[x]=y;
        }
    }
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    unordered_map<int,vector<pair<int,int>>> graph;
    int mst(int n,vector<vector<int>>& edges){
        int sum=0;
        int count=0;
        int idx=0;
        while(count<n-1){
            auto curr=edges[idx];
            if(f(curr[0],parent)!=f(curr[1],parent)){
                un(curr[0],curr[1],parent,rank);
                graph[curr[0]].push_back({curr[1],curr[2]});
                sum+=curr[2];
                count++;
            }
            idx++;
        }
        return sum;
    }
    pair<bool,int> c_pc(int skipIdx,int n,vector<vector<int>>& edges,vector<int>& parent1,vector<int> rank1){
        int sum=0;
        int count=0;
        int idx=0;
        while(idx<edges.size() && count<n-1){
            auto curr=edges[idx];
            if(curr[3]==skipIdx){
                idx++;
                continue;
            }
            if(f(curr[0],parent1)!=f(curr[1],parent1)){
                un(curr[0],curr[1],parent1,rank1);
                sum+=curr[2];
                count++;
            }
            idx++;
        }
        if(count==n-1) return {true,sum};
        return {false,-1};
    }
    int force_include(int forceIdx,int n,vector<vector<int>>& edges,vector<int>& parent1,vector<int> rank1){
        int sum=0;
        int count=0;
        int idx=0;
        for(auto& curr:edges){
            if(curr[3]==forceIdx){
                un(curr[0],curr[1],parent1,rank1);
                sum+=curr[2];
                count++;
                break;
            }
        }
        while(idx<edges.size() && count<n-1){
            auto curr=edges[idx];
            if(curr[3]==forceIdx){
                idx++;
                continue;
            }
            if(f(curr[0],parent1)!=f(curr[1],parent1)){
                un(curr[0],curr[1],parent1,rank1);
                sum+=curr[2];
                count++;
            }
            idx++;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),cmp);

        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        int currwt=mst(n,edges);

        vector<int> c;
        vector<int> pc;

        for(auto curr:edges){
            int originalIdx=curr[3];

            vector<int> parent1(n);
            vector<int> rank1(n,0);
            for(int ii=0;ii<n;ii++) parent1[ii]=ii;

            auto xx=c_pc(originalIdx,n,edges,parent1,rank1);

            if(xx.first==false){
                c.push_back(originalIdx);
                continue;
            } else if(xx.second>currwt){
                c.push_back(originalIdx);
                continue;
            }
            vector<int> parent2(n);
            vector<int> rank2(n,0);
            for(int ii=0;ii<n;ii++) parent2[ii]=ii;

            int forced=force_include(originalIdx,n,edges,parent2,rank2);

            if(forced==currwt){
                pc.push_back(originalIdx);
            }
        }

        return {c,pc};
    }
};