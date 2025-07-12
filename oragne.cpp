class Solution {
  public:
  int n,m;
  vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
  void f(vector<vector<int>>& mat,vector<vector<int>>& visited,int &ans,vector<pair<int,int>>&v){
      queue<pair<int,int>> q;
      for(auto i:v) q.push({i.first,i.second});
      q.push({-1,-1});
      while(q.size()!=0){
          auto curr=q.front();
          int i=curr.first;
          int j=curr.second;
          q.pop();
          if(i==-1 && j==-1){
              if(q.size()!=0){
                  ans++;
                  q.push({-1,-1});
              }
              continue;
          }
          bool flag=false;
          for(int d=0;d<4;d++){
              int nr=i+dir[d][0];
              int nc=j+dir[d][1];
              if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1){
                  mat[nr][nc]=2;
                  visited[nr][nc]=-2;
                  q.push({nr,nc});
                  flag=true;
              }
          }
      }
  }
    int orangesRotting(vector<vector<int>>& mat) {
        vector<pair<int,int>> v;
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2) v.push_back({i,j});
            }
        }
        int ans=0;
        vector<vector<int>> visited(n,vector<int>(m,-1));
        f(mat,visited,ans,v);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) return -1;
            }
        }
        return ans;
    }
};