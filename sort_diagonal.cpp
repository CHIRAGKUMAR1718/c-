class Solution {
public:
    int n,m;

    void f(int sr,int sc,vector<vector<int>>& grid,vector<int>&v,vector<vector<int>>& ans,int& idx,bool flag){
        if(sr<0 || sc<0 || sr>=n || sc>=m) return;
        v.push_back(grid[sr][sc]);
        f(sr+1,sc+1,grid,v,ans,idx,flag);
        sort(v.begin(),v.end());
        if(!flag) reverse(v.begin(),v.end());
        ans[sr][sc]=v[v.size()-idx];
        idx++;
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=n-1;i>=1;i--){
            vector<int> v;
            int idx=1;
            f(0,i,grid,v,ans,idx,true);
        }
        for(int i=0;i<n;i++){
            vector<int> v;
            int idx=1;
            f(i,0,grid,v,ans,idx,false);
        }
        return ans;
    }
};