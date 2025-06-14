class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    bool f(vector<vector<int>>& grid, int h){
        queue<tuple<int,int,int>> q;
        vector<vector<vector<int>>> st_d(n,vector<vector<int>>(m,vector<int>(h+1,1e9)));
        int h0=h-grid[0][0];
        if(h0<=0) return false;
        q.push({0,0,h0});
        st_d[0][0][h0]=0;
        while(q.size()!=0){
            auto [i,j,rh]=q.front();
            if (i==m-1 && j==n-1 && h > 0) return true;
            q.pop();
            for(int d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){ 
                int nh=rh-grid[nr][nc];
                if(nh>0 && st_d[nr][nc][nh] > st_d[i][j][rh] + 1){
                    st_d[nr][nc][nh] = st_d[i][j][rh] + 1;
                    q.push({nr,nc,nh});
                }
                }
            }
        }
        for(int i=0;i<=h;i++){
            if(st_d[n-1][m-1][i]!=1e9) return true;
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        m=grid[0].size();
        return f(grid,health);
    }
};