class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;

    void f(int sr,int sc,vector<vector<int>>& grid,vector<vector<bool>>& visited,int& ans,int count,int target){
        if(grid[sr][sc]==-1) return;
        if(grid[sr][sc]==2 && count!=target) return;
        if(grid[sr][sc]==2 && count==target){
            ans++;
            return;
        }
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==false){
                visited[sr][sc]=true;
                f(nr,nc,grid,visited,ans,count+1,target);
                visited[sr][sc]=false;
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        int sr=0;
        int sc=0;
        int target=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]==-1) target++;
            }
        }
        visited[sr][sc]=true;
        target=n*m-target;
        f(sr,sc,grid,visited,ans,1,target);
        return ans;
    }
};