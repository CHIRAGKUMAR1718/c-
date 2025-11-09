class Solution {
public:
    int n,m;
    int f(int sr,int sc,vector<vector<int>>& grid, int k,int cost,vector<vector<vector<int>>>& dp){
        if(sr<0 || sc<0 || sr>=n || sc>=m) return INT_MIN;
        if(dp[sr][sc][cost]!=-1) return dp[sr][sc][cost];
        int c=0;
        int s=0;
        if(grid[sr][sc]==1){
            s+=1;
            c+=1;
        }
        else if(grid[sr][sc]==2){
            s+=2;
            c+=1;
        }
        if(cost+c>k) return dp[sr][sc][cost]=INT_MIN;
        if(sr==n-1 && sc==m-1) return dp[sr][sc][cost]=s;
        int r=f(sr,sc+1,grid,k,cost+c,dp);
        int d=f(sr+1,sc,grid,k,cost+c,dp);
        int best=max(r,d);
        if(best==INT_MIN) return dp[sr][sc][cost]=INT_MIN;
        return dp[sr][sc][cost]=best+s;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (k+1,-1)));
        int ans=f(0,0,grid,k,0,dp);
        return (ans!=INT_MIN)?ans:-1;
    }
};