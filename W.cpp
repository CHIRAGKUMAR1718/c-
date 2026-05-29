class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    bool f(int sr,int sc,vector<vector<char>>& board,vector<vector<bool>>& visited,string& word,int idx){
        if(board[sr][sc]!=word[idx]) return false;
        if(idx+1==word.size()) return true;
        visited[sr][sc]=true;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc]){
                if(f(nr,nc,board,visited,word,idx+1)) return true;
            }
        }
        visited[sr][sc]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                if(f(i,j,board,visited,word,0)) return true;
            }
        }
        return false;
    }
};