class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& mat){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(mat[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int r=solve(i,j+1,mat);
        int d=solve(i+1,j+1,mat);
        int l=solve(i+1,j,mat);
        return dp[i][j]=1+min({r,d,l});
    }
    int countSquares(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        dp.resize(n+2,vector<int>(m+2,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans+=solve(i,j,mat);
                }
            }
        }
        return ans;
    }
};