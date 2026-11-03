class Solution {
public:
    int dp[505][505][4];
    long long f(int sr,int sc,int R_D,vector<vector<int>>& grid){
        if(sr==n-1 && sc==m-1) return 1;
        long long ans=0;
        if(dp[sr][sc][R_D]!=-1) return dp[sr][sc][R_D];
        if(sr<0 || sc<0 || sr>=n ||sc>=m) return 0;
        if(grid[sr][sc]==1){
            if(R_D==1) ans+=f(sr+1,sc,2,grid);
            else ans+=f(sr,sc+1,1,grid);
        }else{  
            ans+=f(sr+1,sc,2,grid);
            ans+=f(sr,sc+1,1,grid);
        }
        return dp[sr][sc][R_D]=ans%1000000007;;
    }
    int n,m;
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        long long ans=f(0,0,0,grid);
        return ans%1000000007;
    }
};