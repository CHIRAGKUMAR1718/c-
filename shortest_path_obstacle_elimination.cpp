class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    int f(vector<vector<int>>& grid, int k){
        deque<tuple<int,int,int>> q;
        vector<vector<vector<int>>> st_d(n,vector<vector<int>>(m,vector<int>(k+1,1e9)));
        q.push_front({0,0,k});
        st_d[0][0][k]=0;
        while(q.size()!=0){
            auto [i,j,rk]=q.front();
            q.pop_front();
            for(auto d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m ){
                    int nk=rk-grid[nr][nc];
                    if(nk>=0 && st_d[nr][nc][nk]>st_d[i][j][rk]+1){
                        st_d[nr][nc][nk]=st_d[i][j][rk]+1;
                        q.push_back({nr,nc,nk});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k;i++){
            ans=min(ans,st_d[n-1][m-1][i]);
        }
        return (ans==1e9)?-1:ans;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        return f(grid,k);
    }
};