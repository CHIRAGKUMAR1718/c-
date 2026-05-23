class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};


    void dfs(int sr,int sc,vector<vector<int>>& mat,vector<vector<int>>& visited){
        if(visited[sr][sc]==1) return;
        visited[sr][sc]=1;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<mat.size() && nc<mat.size() && mat[nr][nc]==0 &&visited[nr][nc]==0){
                dfs(nr,nc,mat,visited);
            }
        }
    }



    int regionsBySlashes(vector<string>& grid) {
       int r=grid.size();
       int c=grid[0].size();
       vector<vector<int>> mat(r*3,vector<int>(c*3,0));
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='/'){
                mat[i*3][j*3+2]=1;
                mat[i*3+1][j*3+1]=1;
                mat[i*3+2][j*3]=1;
            }else if(grid[i][j]=='\\'){
                mat[i*3][j*3]=1;
                mat[i*3+1][j*3+1]=1;
                mat[i*3+2][j*3+2]=1;
            }
        }
       }


    

       int ans=0;
       vector<vector<int>> visited(r*3,vector<int>(c*3,0));
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(visited[i][j]==1 || mat[i][j]==1) continue;
            ans++;
            dfs(i,j,mat,visited);
        }
       }
       return ans; 
    }
};