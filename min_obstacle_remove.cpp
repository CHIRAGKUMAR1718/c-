class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    void f(vector<vector<int>>& st_d,vector<vector<int>>& grid,vector<vector<int>>& visited){
        deque<pair<int,int>> q;
        q.push_front({0,0});
        st_d[0][0]=0;
        while(q.size()!=0){
            auto curr=q.front();
            q.pop_front();
            int i=curr.first;
            int j=curr.second;
            visited[i][j]=3;
            for(int d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==2){
                    int ewt=grid[nr][nc];
                    if(st_d[nr][nc]>st_d[i][j]+ewt){
                        st_d[nr][nc]=st_d[i][j]+ewt;
                        if(ewt==0) q.push_front({nr,nc});
                        else q.push_back({nr,nc});
                    }
                }
            }
        }
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,2));
        vector<vector<int>> st_d(n,vector<int>(m,1e9));
        f(st_d,grid,visited);
        return st_d[n-1][m-1];
    }
};