class Solution {
public:
    int n;
    int get_parent(int x,vector<int>& parent){
        if(x==parent[x]) return parent[x];
        return parent[x]=get_parent(parent[x],parent);
    }
    void make_group(int x,int y,vector<int>&parent,vector<int>& rank){
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n=s.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto v:pairs) make_group(v[0],v[1],parent,rank);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++) m[get_parent(parent[i],parent)].push_back(i);
        string ans=s;
        for(auto i:m){
            string x="";
            for(int j=0;j<i.second.size();j++){
                x+=s[i.second[j]];
            }
            sort(x.begin(),x.end());
            int idx=0;
            for(int j=0;j<i.second.size();j++){
                ans[i.second[j]]=x[idx++];
            }
        }
        return ans;
    }
};