class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>&b){
        return a[0]>b[0];
    }
    int f(vector<int>& parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=f(parent,parent[x]);
    }
    void dsu(vector<int>& a_parent,vector<int>& a_rank,vector<int>& b_parent,vector<int>& b_rank,int& a_c,int& b_c,int& e_c,vector<vector<int>>& edges){
        for(auto v:edges){
            if(v[0]==1){
                int p1=f(a_parent,v[1]);
                int p2=f(a_parent,v[2]);
                if(p1!=p2){
                    if(a_rank[p1]>=a_rank[p2]){
                        a_rank[p1]++;
                        a_parent[p2]=p1;
                    }else{
                        a_rank[p2]++;
                        a_parent[p1]=p2;
                    }
                    e_c++;
                    a_c--;
                }
            }
            else if(v[0]==2){
                int p1=f(b_parent,v[1]);
                int p2=f(b_parent,v[2]);
                if(p1!=p2){
                    if(b_rank[p1]>=b_rank[p2]){
                        b_rank[p1]++;
                        b_parent[p2]=p1;
                    }else{
                        b_rank[p2]++;
                        b_parent[p1]=p2;
                    }
                    e_c++;
                    b_c--;
                }
            }else{
                int ap1=f(a_parent,v[1]);
        int ap2=f(a_parent,v[2]);
        int bp1=f(b_parent,v[1]);
        int bp2=f(b_parent,v[2]);
        bool flag=false;
        if(ap1!=ap2){
            if(a_rank[ap1]>=a_rank[ap2]){ a_rank[ap1]++; a_parent[ap2]=ap1; }
            else{ a_rank[ap2]++; a_parent[ap1]=ap2; }
            a_c--;
            flag=true;
        }
        if(bp1!=bp2){
            if(b_rank[bp1]>=b_rank[bp2]){ b_rank[bp1]++; b_parent[bp2]=bp1; }
            else{ b_rank[bp2]++; b_parent[bp1]=bp2; }
            b_c--;
            flag=true;
        }
        if(flag) e_c++;
                }
            }
        }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> a_parent(n+1);
        vector<int> a_rank(n+1,0);
        vector<int> b_parent(n+1);
        vector<int> b_rank(n+1,0);
        for(int i=0;i<n+1;i++){
            a_parent[i]=i;
            b_parent[i]=i;
        }
        sort(edges.begin(),edges.end(),cmp);
        int a_c=n;
        int b_c=n;
        int e_c=0;
        dsu(a_parent,a_rank,b_parent,b_rank,a_c,b_c,e_c,edges);
        if(a_c==b_c && a_c==1) return edges.size()-e_c;
        return -1;
    }
};