class Solution {
public:
    int n,m;
    void f(int rs,int re,int cs,int ce,vector<vector<int>>& grid,int k){
        if(rs>re || cs>ce) return;
        vector<int> v;
        for(int i=cs;i<=ce;i++) v.push_back(grid[rs][i]);

        for(int i=rs+1;i<=re;i++) v.push_back(grid[i][ce]);

        for(int i=ce-1;i>=cs;i--) v.push_back(grid[re][i]);

        for(int i=re-1;i>rs;i--) v.push_back(grid[i][cs]);

        int len=v.size();
        len=k%v.size();
        rotate(v.begin(),v.begin()+len,v.end());

        int idx=0;
        for(int i=cs;i<=ce;i++) grid[rs][i]=v[idx++];

        for(int i=rs+1;i<=re;i++) grid[i][ce]=v[idx++];

        for(int i=ce-1;i>=cs;i--) grid[re][i]=v[idx++];

        for(int i=re-1;i>rs;i--) grid[i][cs]=v[idx++];

        f(rs+1,re-1,cs+1,ce-1,grid,k);
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        f(0,n-1,0,m-1,grid,k);
        return grid;
    }
};