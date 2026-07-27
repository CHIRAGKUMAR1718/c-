class Solution {
public:
    int f(int x,vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=f(parent[x],parent);
    }
    void dsu(int sr,int sc,vector<int>&parent,vector<int>& rank){
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

    bool check(int n, vector<vector<int>>& edges, int k,int mid){
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        int count=0;
        for(auto e:edges){
            if(e[3]==1){
            if(e[2]<mid) return false;
            int x=f(e[0],parent);
            int y=f(e[1],parent);
            dsu(x,y,parent,rank);
            count++;
            }
        }
        if(count==n-1) return true;
        for(auto e:edges){
            if(e[3]==0 && e[2]>=mid){
                int x=f(e[0],parent);
                int y=f(e[1],parent);
                if(x!=y){
                    dsu(x,y,parent,rank);
                    count++;
                }
            }
        }
        if(count==n-1) return true;
        for(auto e:edges){
            if(e[3]==0 && e[2]<mid && 2*e[2]>=mid){
                int x=f(e[0],parent);
                int y=f(e[1],parent);
                if(x!=y){
                    dsu(x,y,parent,rank);
                    count++;
                    k--;
                }
            }
        }
        return count==n-1 && k>=0;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto e:edges){
            if(e[3]==1){  
            int x=f(e[0],parent);
            int y=f(e[1],parent);
            if(x==y) return -1;
            dsu(x,y,parent,rank);
            }
        }
        int hi=INT_MIN;
        int lo=INT_MAX;
        for(auto e:edges){
            lo=min(lo,e[2]);
            int mm=(e[3]==1)?e[2]:2*e[2];
            hi=max(hi,mm);
        }
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};