class Solution {
public:
    void f(int sr,int sc,vector<vector<int>>& visited,vector<vector<int>>& mat,int n,int m){
        for(int i=sr+1;i<n;i++){
            if(mat[i][sc]==1 || mat[i][sc]==2) break;
            visited[i][sc]=1;
        }
        for(int i=sr-1;i>=0;i--){
            if(mat[i][sc]==1 || mat[i][sc]==2) break;
            visited[i][sc]=1;
        }
        for(int i=sc+1;i<m;i++){
            if(mat[sr][i]==1 || mat[sr][i]==2) break;
            visited[sr][i]=1;
        }
        for(int i=sc-1;i>=0;i--){
            if(mat[sr][i]==1 || mat[sr][i]==2) break;
            visited[sr][i]=1;
        }
    }
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<guards.size();i++){
            mat[guards[i][0]][guards[i][1]]=1;
            visited[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            mat[walls[i][0]][walls[i][1]]=2;
            visited[walls[i][0]][walls[i][1]]=1;
        }
        for(int i=0;i<guards.size();i++){
            int r=guards[i][0];
            int c=guards[i][1];
            f(r,c,visited,mat,n,m);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0) ans++;
            }
        }
        return ans;
    }
};