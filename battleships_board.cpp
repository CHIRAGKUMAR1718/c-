class Solution {
public:
    int n,m;
    void dfs(int sr,int sc,vector<vector<int>>& visited,vector<vector<char>>& mat){
        if(sr<0 || sc<0 || sr>=n || sc>=m || visited[sr][sc]==1 || mat[sr][sc]=='.') return;
        visited[sr][sc]=1;
        dfs(sr+1,sc,visited,mat);
        dfs(sr-1,sc,visited,mat);
        dfs(sr,sc+1,visited,mat);
        dfs(sr,sc-1,visited,mat);
    }

    int countBattleships(vector<vector<char>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='X' && visited[i][j]==0){
                    ans++;
                    dfs(i,j,visited,mat);
                }
            }
        }
        return ans;
    }
};