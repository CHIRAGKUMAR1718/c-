class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int sr,int sc,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& visited,bool& flag){
        if(grid2[sr][sc]==0) return;
        if(visited[sr][sc]==1) return;
        if(grid1[sr][sc]!=grid2[sr][sc]) flag=false;
        visited[sr][sc]=1;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                dfs(nr,nc,grid1,grid2,visited,flag);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1) continue;
                if(grid2[i][j]==0) continue;
                bool flag=true;
                dfs(i,j,grid1,grid2,visited,flag);
                if(flag) ans++;
            }
        }
        return ans;
    }
};