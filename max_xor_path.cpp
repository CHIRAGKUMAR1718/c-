class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{0,1}};
    int f(int sr,int sc,vector<vector<int>>& grid,int ans,vector<vector<vector<int>>>& dp){
        ans^=grid[sr][sc];
        if(sr==n-1 && sc==m-1) return ans;
        if(dp[sr][sc][ans]!=-1) return dp[sr][sc][ans];
        int result=INT_MAX;
        for(int d=0;d<2;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                int x=f(nr,nc,grid,ans,dp);
                result=min(result,x);
            }
        }
        return dp[sr][sc][ans]=result;
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n+5,vector<vector<int>>(m+5,vector<int>(5000,-1)));
        return f(0,0,grid,0,dp);
    }
};