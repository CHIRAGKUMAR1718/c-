class Solution {
public:
    int n;
    int get_parent(int x,vector<int>& parent){
        if(x==parent[x]) return x;
        return parent[x]=get_parent(parent[x],parent);
    }
    void make_group(int x,int y,vector<int>& parent,vector<int>& rank){
        x=get_parent(x,parent);
        y=get_parent(y,parent);
        if(rank[x]>rank[y]){
            parent[y]=x;
            rank[x]++;
        }else{
            parent[x]=y;
            rank[y]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        n=source.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto v:allowedSwaps){
            make_group(v[0],v[1],parent,rank);
        }
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[get_parent(parent[i],parent)].push_back(i);
        }
        int ans=0;
        for(auto i:m){
            unordered_map<int,int> s;
            unordered_map<int,int> t;
            for(int j=0;j<i.second.size();j++){
                int idx=i.second[j];
                s[source[idx]]++;
                t[target[idx]]++;
            }
            for(auto i:s){
                if(t.count(i.first)) ans+=min(i.second,t[i.first]);
            }
        }
        return n-ans;
    }
};