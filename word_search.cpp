class Solution {
  public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool f(int sr,int sc,vector<vector<char>>& mat,int idx,string& word,vector<vector<int>>& visited){
        if(idx==word.size()) return true;
        visited[sr][sc]=1;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                if(visited[nr][nc]==0 && mat[nr][nc]==word[idx]){
                    if(f(nr,nc,mat,idx+1,word,visited)) return true;
                }
            }
        }
        visited[sr][sc]=0;
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    vector<vector<int>> visited(n,vector<int>(m,0));
                    if(f(i,j,mat,1,word,visited)) return true;
                }
            }
        }
        return false;
    }
};