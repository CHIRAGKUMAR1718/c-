class Solution {
public:
    int n,m;
    int dp[71][71][71];
    int f(int row,int c1,int c2,vector<vector<int>>& grid){
        if(row==n) return 0;
        if(dp[row][c1][c2]!=-1) return dp[row][c1][c2];
        int maxi=0;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                int nc1=c1+d1;
                int nc2=c2+d2;
                if(nc1>=0 && nc1<m && nc2>=0 && nc2<m){
                    int y=grid[row][c1]+((c1!=c2)?grid[row][c2]:0)+f(row+1,nc1,nc2,grid);
                    maxi=max(maxi,y);
                }
            }
        }
        return dp[row][c1][c2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        return f(0,0,m-1,grid);
    }
};